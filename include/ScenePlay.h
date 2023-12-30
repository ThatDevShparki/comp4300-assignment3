#pragma once

#include "Scene.h"
#include <memory>

class ScenePlay : public Scene
{
	struct PlayerConfig
	{
		float       X, Y, CX, CY, SPEED, MAXSPEED, JUMP, GRAVITY;
		std::string WEAPON;
	};

protected:

	std::shared_ptr<Entity> m_player;
	std::string             m_levelPath;
	PlayerConfig            m_playerConfig;
	bool                    m_drawTextures  = true;
	bool                    m_drawCollision = false;
	bool                    m_drawDrawGrid  = false;
	const Vec2              m_gridSize      = { 64, 64 };
	sf::Text                m_gridText;

	void init(const std::string&);
	Vec2 gridToMidPixel(float, float, std::shared_ptr<Entity>);
	void loadLevel(const std::string&);
	void spawnPlayer();
	void spawnBullet(std::shared_ptr<Entity>);
	void sMovement();
	void sLifespan();
	void sCollision();
	void sAnimation();
	void sRender() override;
	void sDoAction(const Action&) override;
	void onEnd() override;
	void setPaused(bool);

public:
	ScenePlay(GameEngine* gameEngine, std::string&);
	void update() override;
};
