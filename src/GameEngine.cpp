#include "GameEngine.h"

#include <iostream>
#include <string>

GameEngine::GameEngine(const std::string& path)
{
	init(path);
}

void GameEngine::init(const std::string& path)
{
	m_assets.loadFromFile(path);
	m_window.create(
		sf::VideoMode::getFullscreenModes().back(),
		"Definitely not mario"
	);
	m_window.setFramerateLimit(60);
	m_window.setVerticalSyncEnabled(true);
}

void GameEngine::run()
{
	while (isRunning())
	{
		update();
	}
}

void GameEngine::update()
{
	sUserInput();
}

void GameEngine::sUserInput()
{
	sf::Event event{};
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			quit();
		}
	}
}


bool GameEngine::isRunning()
{
	return m_running;
}

void GameEngine::quit()
{
	m_running = false;
}

