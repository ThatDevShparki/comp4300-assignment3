#include "Physics.h"

Vec2 Physics::getOverlap(const Entity& a, const Entity& b)
{
	if (!(a.hasComponent<CTransform>() && a.hasComponent<CBoundingBox>() &&
		  b.hasComponent<CTransform>() && b.hasComponent<CBoundingBox>()))
	{
		return { 0.0f, 0.0f };
	}

	const auto& aPos = a.getComponent<CTransform>().pos;
	const auto& bPos = b.getComponent<CTransform>().pos;
	const Vec2 delta = { abs(bPos.x - aPos.x), abs(bPos.y - aPos.y) };

	const auto& aHalfSize = a.getComponent<CBoundingBox>().halfSize;
	const auto& bHalfSize = b.getComponent<CBoundingBox>().halfSize;
	return {
		aHalfSize.x + bHalfSize.x - delta.x,
		aHalfSize.y + bHalfSize.y - delta.y,
	};
}

Vec2 Physics::getPrevOverlap(const Entity& a, const Entity& b)
{
	if (!(a.hasComponent<CTransform>() && a.hasComponent<CBoundingBox>() &&
		  b.hasComponent<CTransform>() && b.hasComponent<CBoundingBox>()))
	{
		return { 0.0f, 0.0f };
	}

	const auto& aPos = a.getComponent<CTransform>().prevPos;
	const auto& bPos = b.getComponent<CTransform>().prevPos;
	const Vec2 delta = { abs(bPos.x - aPos.x), abs(bPos.y - aPos.y) };

	const auto& aHalfSize = a.getComponent<CBoundingBox>().halfSize;
	const auto& bHalfSize = b.getComponent<CBoundingBox>().halfSize;
	return {
		aHalfSize.x + bHalfSize.x - delta.x,
		aHalfSize.y + bHalfSize.y - delta.y,
	};
}