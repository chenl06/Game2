//Chen Luo
//2.20.2023
//Sphere actor

#include "Light.h"
#include "Game.h"
#include "Renderer.h"

Light::Light(Game* game)
	:Actor(game)
	, mLightTime(1.0f)
{
	GetGame()->GetRenderer()->SetAmbientLight(Vector3(0.5f, 0.5f, 0.5f));
	DirectionalLight& dir = GetGame()->GetRenderer()->GetDirectionalLight();
	dir.mDirection = Vector3(0.0f, -0.707f, -0.707f);
	dir.mSpecColor = Vector3(0.8f, 0.8f, 0.8f);
}
//Change the light every delta time
void Light::UpdateActor(float deltaTime) {
	mLightTime -= deltaTime;
	DirectionalLight& dir = GetGame()->GetRenderer()->GetDirectionalLight();
	if (mLightTime <= 0.5f) {
		dir.mDiffuseColor = Vector3(0.00f, 1.00f, 0.00f);
		if (mLightTime <= 0.0f) {
			mLightTime = 1.0f;
		}
	}
	else {
		dir.mDiffuseColor = Vector3(0.78f, 0.88f, 1.0f);
	}
}



	