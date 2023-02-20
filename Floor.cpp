//Chen Luo
//2.20.2023
//Floor actor setting up for floor

#include "Floor.h"
#include "Game.h"
#include "Renderer.h"
#include "MeshComponent.h"

Floor::Floor(Game* game)
	:Actor(game)
{
	SetScale(10.0f);
	MeshComponent* mc = new MeshComponent(this);
	mc->SetMesh(GetGame()->GetRenderer()->GetMesh("Assets/Plane.gpmesh"));
}
