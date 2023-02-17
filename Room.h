#pragma once

#include "PlaneActor.h"
#include "Box.h"

class Room : public Actor
{
public:
	Room(Game* game, Box box);
	//~Room();
private:
	bool hasTopWall;
	bool hasLeftWall;
	bool hasRightWall;
	bool hasBottomWall;
	enum {PLANESIZE = 750};
private:
	PlaneActor *north = NULL;
	PlaneActor *south = NULL;
	PlaneActor *east  = NULL;
	PlaneActor *west  = NULL;

};

