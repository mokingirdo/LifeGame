#include "Deserealizer.h"

Deserealizer::Deserealizer()
{
}

Deserealizer::~Deserealizer()
{
}

Field& Deserealizer::load_field(std::istream& filename)
{
	std::string input;
	static Field field;

	for (unsigned i = 0; i < FIELD_SIZE; i++)
	{
		std::getline(filename, input);
		if (!is_field_cells(input))
			throw std::invalid_argument("It must be field in input file");
		for (unsigned j = 0; j < FIELD_SIZE; j++)
		{
			if (input[j] - '0')
				field[i][j].born();
			else
				field[i][j].die();
		}
	}
	return field;
}

bool Deserealizer::is_field_cells(std::string input)
{
	if (input.size() != FIELD_SIZE)
		return false;
	for (unsigned i = 0; i < FIELD_SIZE; i++)
	{
		if (input[i] - '0' != 0 && input[i] - '0' != 1)
			return false;
	}
	return true;
}