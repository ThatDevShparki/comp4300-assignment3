#include "Animation.h"


Animation::Animation() = default;

Animation::Animation(const std::string& name, const sf::Texture& t)
	: m_name(name)
{
	m_sprite.setTexture(t);
}

Animation::Animation(
	std::string name,
	const sf::Texture& t,
	size_t frameCount,
	size_t speed
)
	: m_frameCount(frameCount), m_speed(speed), m_name(std::move(name))
{
	m_sprite.setTexture(t);
}

void Animation::update()
{
	// TODO: implement this
}

bool Animation::hasEnded() const
{
	// TODO: implement this
	return false;
}

const std::string& Animation::getName() const
{
	return m_name;
}

const Vec2& Animation::getSize() const
{
	return m_size;
}

sf::Sprite Animation::getSprite() const
{
	return m_sprite;
}