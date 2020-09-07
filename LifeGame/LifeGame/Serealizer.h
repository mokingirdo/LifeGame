#pragma once
#include <fstream>
#include "Field.h"

class Serealizer
{
	Field& field;

public:

	Serealizer(Field&);
	~Serealizer();

	void store_field(std::string&);
};

