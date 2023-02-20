//Chen Luo
//2.20.2023
//Setting up for Wall left. right. forward, backward
#include "Wall.h"
#include "Game.h"
#include "Renderer.h"
#include "MeshComponent.h"

Wall::Wall(Game* game)
	:Actor(game)
{
	SetScale(10.0f);
	MeshComponent* mc = new MeshComponent(this);
	mc->SetMesh(GetGame()->GetRenderer()->GetMesh("Assets/Wall.gpmesh"));
}
