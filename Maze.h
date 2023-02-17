#pragma once
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
#include <list>
#include "Box.h"
#include <random>
#include <stack>

class Maze
{
public:  
	Maze(int nRows, int nColumns);
	~Maze();
	void RemoveWallsBetween (Box& firstBox, Box& secondBox);
	void makeMaze();
	void breakRandomWalls(float percentageToBreak);
	int NRows;
	int NColumns;
	Box **maze;
private:
	std::stack<Box> pathFromTop;
	std::vector<Box> GetUnvisitedNeighbors(int row,int column);
};

