#include "Room.h"
#include "Box.h"
#include "Renderer.h"
#include "MeshComponent.h"
#include "Game.h"

Room::Room(Game* game, Box box) 
	:Actor(game)
{
	// Make Floor
	SetScale(PLANESIZE / 100.0f);
	MeshComponent* mc = new MeshComponent(this);
	mc->SetMesh(GetGame()->GetRenderer()->GetMesh("Assets/Plane.gpmesh"));
	SetPosition(Vector3(box.Column * PLANESIZE, box.Row * PLANESIZE * -1.0f, -100.0f));

	// Make North South Walls
	Quaternion q = Quaternion(Vector3::UnitX, Math::PiOver2);
	if (box.hasNorthWall)
	{
		north = new PlaneActor(game);
		north->SetScale(this->GetScale());
		north->SetPosition(Vector3(GetPosition().x, GetPosition().y + (PLANESIZE / 2), 0));
		north->SetRotation(q);
	}
	if (box.hasSouthWall)
	{
		south = new PlaneActor(game);
		south->SetScale(this->GetScale());
		south->SetPosition(Vector3(GetPosition().x, GetPosition().y - (PLANESIZE / 2), 0));
		south->SetRotation(q);
	}

	// Make East West Wall
	q = Quaternion(Vector3::UnitY, Math::PiOver2);
	if (box.hasWestWall)
	{
		west = new PlaneActor(game);
		west->SetScale(this->GetScale());
		west->SetPosition(Vector3(GetPosition().x - (PLANESIZE / 2), GetPosition().y, 0));
		west->SetRotation(q);
	}
	if (box.hasEastWall)
	{
		east = new PlaneActor(game);
		east->SetScale(this->GetScale());
		east->SetPosition(Vector3(GetPosition().x + (PLANESIZE / 2), GetPosition().y, 0));
		east->SetRotation(q);
	}
}


//Room::~Room()
//{
//}
