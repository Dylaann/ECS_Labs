#pragma once


#include "entityx/Entity.h"

/// <summary>
/// @Author Ross Palmer
/// @Version 1.0
/// @brief A component to represent the game background image.
///
/// </summary>
struct Node : public entityx::Component<Node>
{
	/// <summary>
	/// Default constructor
	/// </summary>
	Node();

	Node(int radius);

	int m_radius;
	bool m_current = false;
};