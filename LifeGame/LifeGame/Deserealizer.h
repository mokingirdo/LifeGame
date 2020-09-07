#pragma once
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include "Field.h"

class Deserealizer
{
public:

	Deserealizer();
	~Deserealizer();

	Field& load_field(std::istream& filename);
	bool is_field_cells(std::string input);
};

