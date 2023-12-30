#pragma once

#include "GameEngine.h"
#include "Scene.h"
#include <vector>


class SceneMenu : public Scene
{
protected:

	std::string              m_title;
	std::vector<std::string> m_menuStrings;
	std::vector<std::string> m_levelPaths;
	sf::Text                 m_menuText;
	size_t                   m_selectedMenuIndex;

	void init();
	void update() override;
	void onEnd() override;
	void sDoAction(const Action& action) override;

public:

	explicit SceneMenu(GameEngine* gameEngine = nullptr);
	void sRender() override;

};