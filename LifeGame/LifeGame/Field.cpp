#include "Field.h"

Field::Field()
{
	field.resize(FIELD_SIZE);
	for (int i = 0; i < FIELD_SIZE; i++)
		field[i].resize(FIELD_SIZE);
}

Field::~Field()
{
}

std::vector<Cell>& Field::operator[](int x_)
{
	return field[x_];
}


const bool Field::operator==(Field& prototype_) const
{
	for (int i = 0; i < FIELD_SIZE; i++)
		for (int j = 0; j < FIELD_SIZE; j++)
			if (prototype_[i][j].alive() != field[i][j].alive())
				return false;
	return true;
}

const std::vector<Cell>& Field::operator[](int x_) const
{
	return field[x_];
}