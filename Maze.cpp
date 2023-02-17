#include "Maze.h"

Maze::Maze (int nRows, int nColumns)
	{
		NRows = nRows;
		NColumns = nColumns;
		maze = new Box*[NRows];
		for (int i = 0; i < NRows; i++)
		{
			maze[i] = new Box[NColumns];
		}
		for (int row = 0; row < nRows; ++row)
		{
			for (int column = 0; column < nColumns; ++column)
			{
				maze[row][column] = Box(row, column);
			}
		}
		// change to random seed before publishing
		makeMaze();
	}

Maze::~Maze()
{
	delete[]maze;
}

void Maze::RemoveWallsBetween(Box& firstBox,
			Box& secondBox)
	{
		// If they are in the same column
		// Break a horizontal wall
		if (firstBox.Column == secondBox.Column)
		{
			// If first box is above the second
			if (firstBox.Row < secondBox.Row)
			{
				firstBox.hasSouthWall = false;
				secondBox.hasNorthWall = false;
			}
			else
			{
				secondBox.hasSouthWall = false;
				firstBox.hasNorthWall = false;
			}
		}
		else
		{
			if (firstBox.Row == secondBox.Row)
			{
				if (firstBox.Column < secondBox.Column)
				{
					firstBox.hasEastWall = false;
					secondBox.hasWestWall = false;
				}
				else
				{
					secondBox.hasEastWall = false;
					firstBox.hasWestWall = false;
				}
			}
		}
	}

void Maze::makeMaze()
	{
		// Algorithm to build a rectangular maze
		//   Make a grid of nRowsxnColumns Boxes
		//      each box has 4 walls (North, South, East, West)
		//      each box can be marked "visited" (boolean)
		//  Make the top-left box the initial box
		//  Mark the box as visited.  Make this box the current box
		//  While there are unvisited boxes
		//     if the current box has unvisited neighbors
		//         Choose a randomly select unvisited neighbor
		//         Push the current box on a stack
		//         Remove the walls between the current box
		//         and the chosen box.
		//         Make the chosen box the current box and
		//         mark it visited.
		//     else
		//          Pop a box from the stack
		//          Make the popped box the current cell.

		// Set topleft box to visited
		int currentRow = 0;
		int currentColumn = 0;
		maze[currentRow][currentColumn].hasBeenVisited = true;
		int nBoxesVisited = 1;
		int nBoxesInMaze = NRows * NColumns;
		pathFromTop.push(maze[currentRow][currentColumn]);

		while (nBoxesVisited < nBoxesInMaze)
		{
			Box nextBox;
			Box poppedBox = Box(-1, -1);

			std::vector<Box> unvisitedNeighbors;
			// find a random unvisited neighbor to current.
			do
			{
				unvisitedNeighbors = GetUnvisitedNeighbors(currentRow,
						currentColumn);

				if (unvisitedNeighbors.size() == 0)
				{
					poppedBox = pathFromTop.top();
					pathFromTop.pop();
					currentRow = poppedBox.Row;
					currentColumn = poppedBox.Column;
				}
			} while (unvisitedNeighbors.size() == 0);

			if (poppedBox.Row != -1 && poppedBox.Column != -1)
			{
				pathFromTop.push(maze[poppedBox.Row][poppedBox.Column]);
				//pathFromTop.push(poppedBox);
			}

			// We have unvisited neighbors
			// Pick a random unvisited neighbor
			nextBox = unvisitedNeighbors[rand()
				% unvisitedNeighbors.size()];

			RemoveWallsBetween(maze[currentRow][currentColumn],
				maze[nextBox.Row][nextBox.Column]);

			if (!nextBox.hasBeenVisited)
			{
				maze[nextBox.Row][nextBox.Column].hasBeenVisited = true;
				++nBoxesVisited;
			}


			// Push the box on the stack
			pathFromTop.push(maze[nextBox.Row][nextBox.Column]);
			//pathFromTop.push(nextBox);

			currentRow = nextBox.Row;
			currentColumn = nextBox.Column;
		}
	}

std::vector<Box> Maze::GetUnvisitedNeighbors(int row,
			int column)
	{
		// Create a new list 
		std::vector<Box> unvistedList;

		if ((row - 1) >= 0 &&
			!maze[row - 1][column].hasBeenVisited)
			unvistedList.emplace_back(maze[row - 1][column]);

		if ((column - 1) >= 0 &&
			!maze[row][column - 1].hasBeenVisited)
			unvistedList.emplace_back(maze[row][column - 1]);

		if ((row + 1) < NRows &&
			!maze[row + 1][column].hasBeenVisited)
			unvistedList.emplace_back(maze[row + 1][column]);

		if ((column + 1) < NColumns &&
			!maze[row][column + 1].hasBeenVisited)
			unvistedList.emplace_back(maze[row][column + 1]);

		return unvistedList;
	}

void Maze::breakRandomWalls(float percentageToBreak)
		{
			int randomMax = 1000;
			float fRandomMax = (float)randomMax;
			for (int row = 0; row < NRows - 1; ++row)
			{
				for (int column = 0; column < NColumns - 1; ++column)
				{
					if (((rand() % randomMax) / fRandomMax)
						<= percentageToBreak)
					{
						if ((rand() & 1) == 1)
						{
							RemoveWallsBetween(maze[row][column],
								maze[row][column + 1]);
						}
						else
						{
							RemoveWallsBetween(maze[row][column],
								maze[row + 1][column]);
						}
					}
				}
			}
		}

