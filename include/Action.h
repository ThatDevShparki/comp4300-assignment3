#pragma once

#include <string>

class Action
{
	std::string m_name;
	std::string m_type;

public:
	Action();
	Action(const std::string& n, const std::string& t);

	const std::string& name() const;
	const std::string& type() const;
};