#include "Animation.h"


Animation::Animation() = default;

Animation::Animation(const std::string& name, const sf::Texture& t)
	: Animation(name, t, 1, 0)
{
}

Animation::Animation(
	std::string name,
	const sf::Texture& t,
	size_t frameCount,
	size_t speed
)
	: m_sprite(t)
	, m_frameCount(frameCount)
	, m_currentFrame(0)
	, m_speed(speed)
	, m_name(name)
{
	m_size = Vec2(float(t.getSize().x), float(t.getSize().y));
	m_sprite.setOrigin(m_size.x / 2.0f, m_size.y / 2.0f);
	m_sprite.setTextureRect(
		sf::IntRect(
			std::floor(m_currentFrame / m_frameCount) * m_size.x,
			0,
			m_size.x,
			m_size.y
		)
	);
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