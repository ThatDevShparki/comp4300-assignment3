#include "SceneMenu.h"
#include "ScenePlay.h"
#include <iostream>

SceneMenu::SceneMenu(GameEngine* gameEngine)
{
	m_game = gameEngine;
}

void SceneMenu::init()
{
	// register levels
	m_menuStrings = { "Level A", "Level B", "Level C", "Level D", "Level E",
					  "Level F" };
	m_levelPaths  = { "", "", "", "", "", "" };

	// register actions
	registerAction(sf::Keyboard::Escape, "QUIT");
	registerAction(sf::Keyboard::W, "UP");
	registerAction(sf::Keyboard::Up, "UP");
	registerAction(sf::Keyboard::S, "DOWN");
	registerAction(sf::Keyboard::Down, "DOWN");
	registerAction(sf::Keyboard::Enter, "ENTER");
}

void SceneMenu::update()
{
	// TODO: implement this
}

void SceneMenu::onEnd()
{
	m_game->quit();
}

void SceneMenu::sDoAction(const Action& action)
{
	if (action.type() == "START")
	{
		if (action.name() == "QUIT")
		{
			onEnd();
		}
		else if (action.name() == "ENTER")
		{
			m_game->changeScene(
				m_menuStrings[m_selectedMenuIndex],
				std::make_shared<ScenePlay>(
					m_game,
					m_levelPaths[m_selectedMenuIndex]
				)
			);
		}
		else if (action.name() == "UP")
		{
			if (m_selectedMenuIndex + 1 < m_menuStrings.size())
			{
				m_selectedMenuIndex++;
			}
		}
		else if (action.name() == "DOWN")
		{
			if (m_selectedMenuIndex - 1 > 0)
			{
				m_selectedMenuIndex--;
			}
		}
	}
}

void SceneMenu::sRender()
{
	// TODO: implement this
}