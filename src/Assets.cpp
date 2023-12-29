#include "Assets.h"

Assets::Assets() = default;


void Assets::addTexture(const std::string& name, const std::string& path)
{
	// TODO: implement this
}

void Assets::addAnimation(const std::string& name, const Animation& animation)
{
	// TODO: implement this
}

void Assets::addFont(const std::string& name, const std::string& path)
{
	// TODO: implement this
}


const sf::Texture& Assets::getTexture(const std::string& name) const
{
	return m_textures.at(name);
}

const Animation& Assets::getAnimation(const std::string& name) const
{
	return m_animations.at(name);
}

const sf::Font& Assets::getfont(const std::string& name) const
{
	return m_fonts.at(name);
}


void Assets::loadFromFile(const std::string& path)
{
	// TODO: implement this
}