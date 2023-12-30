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


std::shared_ptr<Scene> GameEngine::currentScene()
{
	return m_scenes[m_currentScene];
}

void GameEngine::changeScene(
	const std::string& sceneName,
	std::shared_ptr<Scene> scene,
	bool endCurrentScene
)
{
	// TODO: implement this
}


void GameEngine::quit()
{
	m_running = false;
}

void GameEngine::run()
{
	while (isRunning())
	{
		update();
	}
}


sf::RenderWindow& GameEngine::window()
{
	return m_window;
}

const Assets& GameEngine::assets() const
{
	return m_assets;
}

bool GameEngine::isRunning() const
{
	return m_running;
}

