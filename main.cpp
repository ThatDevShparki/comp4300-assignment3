#include <iostream>

#include "Vec2.h"

class Component
{
};


class CTransform : public Component
{
public:
	Vec2  pos     = { 0.0f, 0.0f };
	Vec2  prevPos = { 0.0f, 0.0f };
	Vec2  scale   = { 0.0f, 0.0f };
	Vec2  speed   = { 0.0f, 0.0f };
	float angle   = 0;
};

class CBoundingBox : public Component
{
public:
	Vec2 size;
	Vec2 halfSize;

	CBoundingBox(const Vec2& s)
		: size(s), halfSize(s.x / 2, s.y / 2)
	{
	}
};




int main()
{
	std::cout << "Hello, World!" << std::endl;
	return 0;

	sf::Event event;

	if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased)
	{
		if (currentScene()->getActionMap().find(event.key.code) == currentScene()->getActionMap().end()) {continue;}
		const std::string actionType = (event.type == sf::Event::KeyPressed) ? "START" : "END";
		currentScene()->doAction(Action(currentScene()->getActionMap().at(event.key.code), actionType))
	}
}
