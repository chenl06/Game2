//Chen Luo
//2.20.2023
//Sphere actor

#include "Sphere.h"
#include "Game.h"
#include "Renderer.h"
#include "MeshComponent.h"
#include "MoveComponent.h"

Sphere::Sphere(Game* game)
	:Actor(game)
{
	//Setting up the position
	SetPosition(Vector3(200.0f, -75.0f, 0.0f));
	SetScale(3.0f);

	SetScale(5.0f);
	MeshComponent* mc = new MeshComponent(this);
	mc->SetMesh(GetGame()->GetRenderer()->GetMesh("Assets/Sphere.gpmesh"));
	
	//MoveComponent set the motion of the sphere
	MoveComponent* move = new MoveComponent(this);
	move->SetForwardSpeed(100.0f);
}
