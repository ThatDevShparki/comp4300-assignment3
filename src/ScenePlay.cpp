#include "ScenePlay.h"

ScenePlay::ScenePlay(GameEngine* gameEngine, std::string& levelPath)
{
	m_game = gameEngine;
	init(levelPath);
}

void ScenePlay::init(const std::string& levelPath)
{
	m_levelPath = levelPath;
}

Vec2 ScenePlay::gridToMidPixel(float x, float y, std::shared_ptr<Entity> entity)
{
	// TODO: implement this
	return { 0.0f, 0.0f };
}

void ScenePlay::onEnd()
{
	// TODO: implement this
}

void ScenePlay::setPaused(bool paused)
{
	m_pause = paused;
}


void ScenePlay::loadLevel(const std::string&)
{
	// TODO: implement this
}

void ScenePlay::spawnPlayer()
{
	// TODO: implement this
}

void ScenePlay::spawnBullet(std::shared_ptr<Entity> entity)
{
	// TODO: implement this
}

void ScenePlay::sMovement()
{
	// TODO: implement this
}

void ScenePlay::sLifespan()
{
	// TODO: implement this
}

void ScenePlay::sCollision()
{
	// TODO: implement this
}

void ScenePlay::sAnimation()
{
	// TODO: implement this
}

void ScenePlay::sRender()
{
	// TODO: implement this
}

void ScenePlay::sDoAction(const Action& action)
{
	// TODO: implement this
}

void ScenePlay::update()
{
	// TODO: implement this
}