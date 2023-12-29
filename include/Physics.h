#pragma once

#include <memory>
#include "Entity.h"
#include "Vec2.h"

class Physics
{
public:
	static Vec2 getOverlap(const Entity& a, const Entity& b);
	static Vec2 getPrevOverlap(const Entity& a, const Entity& b);
};