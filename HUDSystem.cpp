#include "HUDSystem.h"
#include <string>

using namespace entityx;

HUDSystem::HUDSystem(sf::RenderWindow & window) : m_window(window)
{
	timer.restart();

	if (!m_font.loadFromFile("LDFComicSans.ttf"))
	{
		std::cout << "Error" << std::endl;
	}

	m_current.setCharacterSize(32);
	m_current.setPosition(5, 5);
	m_current.setFont(m_font);
	m_time.setCharacterSize(32);
	m_time.setPosition(5, 35);
	m_time.setFont(m_font);
}

void HUDSystem::update(entityx::EntityManager & entities, entityx::EventManager & events, double dt)
{

	for (Entity entity : entities.entities_with_components(position, node))
	{
			sf::CircleShape hitCircle(node->m_radius);
			hitCircle.setPosition(position->m_position);
			hitCircle.setFillColor(sf::Color::Red);
			hitCircle.setOutlineColor(sf::Color::Black);
			m_window.draw(hitCircle);
	}

	if (newPath == 20)
	{
		count = 1;
	}

	if (newPath < 20 && (count == 0))
	{
		m_time.setString("Lap Time: " + std::to_string(timer.getElapsedTime().asSeconds()));
	}

	m_current.setString("Current Node number: " + std::to_string(newPath));
	m_window.draw(m_current);
	m_window.draw(m_time);
}

void HUDSystem::configure(entityx::EventManager& events)
{
	events.subscribe<EvReportNewWaypoint>(*this);

}

void HUDSystem::receive(const EvReportNewWaypoint& e)
{
	newPath = e.m_Path;
}
