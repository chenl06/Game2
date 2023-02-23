//Chen Luo
//2.20.2023

#pragma once
#include "Actor.h"

class Light : public Actor
{
public:
	Light(class Game* game);
	void UpdateActor(float deltaTime) override;
private:
	float mLightTime;
};
