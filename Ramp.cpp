// John Jaminet

#include "PlaneActor.h"
#include "Ramp.h"
#include "Game.h"
#include "Renderer.h"
#include "MeshComponent.h"

Ramp::Ramp(Game* game)
	:Actor(game)
{
	for (int i = 0; i < NUM_PLANES; i++)
	{
		planes[i] = new PlaneActor(game);
	}
	Quaternion q(Vector3(0.0f, 30.0f*DEGREE_TO_RADIAN, 0.0f));
	planes[0]->SetRotation(q);
	MeshComponent* mc = new MeshComponent(this);
	mc->SetMesh(GetGame()->GetRenderer()->GetMesh("Assets/Plane.gpmesh"));
}