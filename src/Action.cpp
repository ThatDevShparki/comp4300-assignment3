#include "Action.h"

Action::Action() = default;

Action::Action(const std::string& n, const std::string& t)
	: m_name(n), m_type(t)
{
}

const std::string& Action::name() const
{
	return m_name;
}

const std::string& Action::type() const
{
	return m_type;
}