#pragma once

#include "entityx/Event.h"
#include "entityx/Entity.h"
#include <SFML/Graphics.hpp>
#include <Thor/Vectors.hpp>
#include <iostream>

struct Text : public entityx::Component<Text>
{
	/// <summary>
	/// Default constructor
	/// </summary>
	Text(const sf::Vector2f& position, sf::Text text);

	sf::Vector2f m_position;
	sf::Font m_font;
	sf::Text m_text;
};