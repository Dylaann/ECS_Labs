#pragma once
#include "entityx/Event.h"
#include "entityx/Entity.h"
#include "utils/LevelLoader.h"
#include "components/Position.h"
#include "Node.h"
#include <SFML/Graphics.hpp>
#include <Thor/Vectors.hpp>
#include <iostream>
#include <queue>

class HUDSystem
{
public:
	HUDSystem();

	void update(entityx::EntityManager &entities,
		entityx::EventManager &events,
		double dt);

private:

};