#pragma once
#include "Cell.h"

#include <vector>

const int FIELD_SIZE = 10;

class Field
{
	std::vector<std::vector<Cell>> field;

public:

	Field();
	~Field();

	std::vector<Cell>& operator[](int);
	const std::vector<Cell>& operator[](int) const;
	const bool operator==(Field&) const;
};

