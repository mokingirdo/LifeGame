#include "Serealizer.h"

Serealizer::Serealizer(Field& f) : field(f)
{
}

Serealizer::~Serealizer()
{
}

void Serealizer::store_field(std::string& filename)
{
	std::ofstream file(filename);
	for (unsigned i = 0; i < FIELD_SIZE; i++)
	{
		for (unsigned j = 0; j < FIELD_SIZE; j++)
			file << field[i][j].alive();
		file << std::endl;
	}
	file.close();
}
