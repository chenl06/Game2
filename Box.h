#pragma once
class Box
{
public:
	Box() {}
	Box(int row, int column)
	{
		Row = row;
		Column = column;
	}

	bool hasBeenVisited = false;
	bool hasNorthWall = true;
	bool hasSouthWall = true;
	bool hasEastWall = true;
	bool hasWestWall = true;

	int Row;
	int Column;

	bool Equals(Box other);

private:
};

