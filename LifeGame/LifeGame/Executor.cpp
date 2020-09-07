#include "Executor.h"

Executor::Executor(Field& f): ser(f), field(f)
{
}

Executor::~Executor()
{
}

void Executor::strategy_executor(Strategy& s, std::string buf)
{
	int num = 0;
	enum com { RESET, SET, CLEAR, STEP, BACK };
	try 
	{
		switch (buf[1] - '0')
		{
		case RESET:
			s.reset();
			return;
		case SET:
			s.set(buf[2] - 'A', buf[3] - '0');
			return;
		case CLEAR:
			s.clear(buf[2] - 'A', buf[3] - '0');
		case STEP: case BACK: 

		call_step_or_back(s, buf);
		return;
		}
	}
		catch (char* str) { std::cout << str << std::endl; }
}

void Executor::call_step_or_back(Strategy& s, std::string buf)
{
	size_t num = 0;

	system("CLS");
	for (unsigned i = 0; i < buf.size() - 2; num += buf[i + 2] - '0', i++) num *= 10;
	if (num > 1) num--; if (num == 0) return;
 	try
	{
		while (num--)
		{
			if (buf[1] - '0' == 3)
				s.step();
			else
				s.back();
		}
	}
		catch (char* str) { std::cout << str << std::endl; }
		catch (unsigned i){std::cout << "Occurred the loop, the current configuration matches\
										 the configuration in step " << i << std::endl;}
		if (buf[2] == '1' && buf.size() == 2)
			View::print_field(s.get_field(), s.get_step());
}

void Executor::serealizer_executor(std::string& filename)
{
	ser.store_field(filename);
}

void Executor::deserealizer_executor(std::string& filename)
{
	std::ifstream file(filename);
	try { field = des.load_field(file); }
	catch (std::invalid_argument) { std::cout << "It must be field in input file\n"; }
	file.close();
}

bool Executor::call_command(std::string buf, Strategy& s)
{
	enum { COMMAND = '0', HELP = '1', SAVE = '2', LOAD = '3', EXIT = '4', EXCEPTION = '5' };
	switch (buf[0])
	{
	case COMMAND: 
		strategy_executor(s, buf);
		return true;
	case HELP:
		View::print_help();
		return true;
	case SAVE:
		buf.erase(buf.begin());
		serealizer_executor(buf);
		return true;
	case LOAD:
		buf.erase(buf.begin());
		try{ deserealizer_executor(buf);}
		catch (std::invalid_argument) { std::cout << "Could not open file for download\n";
		return true;}
		s.load(s.get_field());
		return true;
	case EXIT:
		return false;
	case EXCEPTION:
		std::cout << " In the game there is no such commad, please read the rules again\n";
		View::print_help();
		return true;
	}
}