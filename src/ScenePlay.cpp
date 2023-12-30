#include "ScenePlay.h"

ScenePlay::ScenePlay(GameEngine* gameEngine, const std::string& levelPath)
	: m_levelPath(levelPath)
{
	init(m_levelPath);
}

void ScenePlay::init(const std::string& levelPath)
{
	registerAction(sf::Keyboard::Escape, "QUIT");
	registerAction(sf::Keyboard::P, "PAUSE");
	registerAction(sf::Keyboard::T, "TOGGLE_TEXTURE");
	registerAction(sf::Keyboard::C, "TOGGLE_COLLISION");
	registerAction(sf::Keyboard::G, "TOGGLE_GRID");
	registerAction(sf::Keyboard::W, "UP");
	registerAction(sf::Keyboard::A, "LEFT");
	registerAction(sf::Keyboard::S, "DOWN");
	registerAction(sf::Keyboard::D, "RIGHT");
	registerAction(sf::Keyboard::Space, "SHOOT");

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
	m_paused = paused;
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
	if (action.type() == "START")
	{
		if (action.name() == "QUIT")
		{
			onEnd();
		}
		else if (action.name() == "PAUSE")
		{
			setPaused(!m_paused);
		}
		else if (action.name() == "TOGGLE_TEXTURE")
		{
			m_drawTextures = !m_drawTextures;
		}
		else if (action.name() == "TOGGLE_COLLISION")
		{
			m_drawCollision = !m_drawCollision;
		}
		else if (action.name() == "TOGGLE_GRID")
		{
			m_drawGrid = !m_drawGrid;
		}
		else if (action.name() == "UP")
		{
			m_player->getComponent<CInput>().up = true;
		}
		else if (action.name() == "DOWN")
		{
			m_player->getComponent<CInput>().down = true;
		}
		else if (action.name() == "LEFT")
		{
			m_player->getComponent<CInput>().left = true;
		}
		else if (action.name() == "RIGHT")
		{
			m_player->getComponent<CInput>().right = true;
		}
		else if (action.name() == "SHOOT")
		{
			m_player->getComponent<CInput>().shoot = true;
		}
	}
	else if (action.type() == "END")
	{
		if (action.name() == "UP")
		{
			m_player->getComponent<CInput>().up = false;
		}
		else if (action.name() == "DOWN")
		{
			m_player->getComponent<CInput>().down = false;
		}
		else if (action.name() == "LEFT")
		{
			m_player->getComponent<CInput>().left = false;
		}
		else if (action.name() == "RIGHT")
		{
			m_player->getComponent<CInput>().right = false;
		}
		else if (action.name() == "SHOOT")
		{
			m_player->getComponent<CInput>().shoot = false;
		}
	}
}

void ScenePlay::update()
{
	// TODO: implement this
}