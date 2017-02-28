#pragma once

#include "entityx/System.h"
#include "entityx/Event.h"
#include "systems/Events.h"
#include "utils/LevelLoader.h"
#include "EntityCreator.h"
#include "ResourcePath.hpp"
#include "AI\TankAi.h"
#include <SFML/Graphics.hpp>
#include "components/Position.h"
#include "Node.h"

class HUDSystem : public entityx::System<HUDSystem>, public entityx::Receiver<HUDSystem>
{
public:
	HUDSystem(sf::RenderWindow& window);

	void update(entityx::EntityManager& entities,
		entityx::EventManager& events,
		double dt);

	void configure(entityx::EventManager& events);

	void receive(const EvReportNewWaypoint& e);

private:

	sf::RenderWindow& m_window;
	sf::Clock timer;
	sf::Text m_current;
	sf::Text m_time;
	sf::Font m_font;
	Node::Handle node;
	Position::Handle position;
	int newPath;
	int count = 0;

};
