#pragma once

#include "Action.h"
#include "EntityManager.h"
#include "GameEngine.h"

#include <cstddef>
#include <map>

class GameEngine;

typedef std::map<int, std::string> ActionMap;

class Scene
{
protected:

	GameEngine* m_game = nullptr;
	EntityManager m_entityManager;
	ActionMap     m_actionMap;
	bool          m_paused       = false;
	bool          m_hasEnded     = false;
	size_t        m_currentFrame = 0;

	virtual void onEnd() = 0;
	void setPaused(bool paused);

public:

	Scene();
	explicit Scene(GameEngine* gameEngine);
	virtual ~Scene();

	virtual void update() = 0;
	virtual void sRender() = 0;

	virtual void doAction(const Action& action);
	void simulate(size_t frames);

	[[nodiscard]] size_t width() const;
	[[nodiscard]] size_t height() const;
	[[nodiscard]] size_t currentFrame() const;

	[[nodiscard]] bool hasEnded() const;
	void drawLine(const Vec2& p1, const Vec2& p2);


	/* handle actions */

	void registerAction(int inputKey, const std::string& actionName);
	virtual void sDoAction(const Action& action) = 0;
	ActionMap& getActionMap();
};
