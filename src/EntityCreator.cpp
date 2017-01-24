#include "EntityCreator.h"

BackgroundCreator::BackgroundCreator(const std::string& fileName)
	: m_fileName(fileName)
{
}

void BackgroundCreator::create(entityx::Entity& entity)
{
	entity.assign<Position>();
	entity.assign<Background>();
}

TankBaseCreator::TankBaseCreator(sf::Vector2f position, bool isAi)
: m_position(position)
, m_isAi(isAi)
{
}

void TankBaseCreator::create(entityx::Entity& entity)
{
	auto volume = Volume();
	volume.m_box = CollisionBox(80, 43);	
	entity.assign<Tank>(entity.id());	
	entity.assign<Motion>(0);
	entity.assign<Position>(m_position, 0.0);
	entity.assign<Volume>(volume);	
	
	if (m_isAi)
	{
		// TODO: Assign relevant components for AI
	}
	else
	{
		entity.assign<Display>(sf::IntRect(2, 43, 79, 43));
		entity.assign<PlayerControl>();
	}
}

TurretCreator::TurretCreator(TankData const& tankData, 
	                         entityx::Entity& parentEntity,
	                         bool isAi)
: m_tankData(tankData)
, m_parentEntity(parentEntity)
, m_isAi(isAi)
{
}

void TurretCreator::create(entityx::Entity& entity)
{
	auto volume = Volume();
	volume.m_box = CollisionBox(81, 30);	

	entity.assign<Turret>(0.0, m_tankData.m_maxProjectiles, 0.0, m_tankData.m_reloadTime, false);
	entity.assign<Motion>(0);	
	entity.assign<Position>(sf::Vector2f(m_tankData.m_position.x, m_tankData.m_position.y), 0.0);
	entity.assign<Volume>(volume);
	
	entity.assign<Parent>(m_parentEntity);	
	// Solution for Turret problem here:
	// http://gamedev.stackexchange.com/questions/31888/in-an-entity-component-system-engine-how-do-i-deal-with-groups-of-dependent-ent
	if (m_isAi)
	{
		// TODO: Assign relevant components for AI
	}
	else
	{
		entity.assign<Display>(sf::IntRect(19, 1, 83, 31)); 	
		entity.assign<PlayerControl>();
	}
}
