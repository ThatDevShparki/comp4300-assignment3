#pragma once

#include "Animation.h"


class Component
{
public:
	bool has = false;
};


class CLifespan : public Component
{
public:
	int lifespan     = 0;
	int frameCreated = 0;

	CLifespan() = default;

	CLifespan(int duration, int frame)
		: lifespan(duration), frameCreated(frame)
	{
	};
};

class CTransform : public Component
{
public:
	Vec2  pos     = {};
	Vec2  prevPos = {};
	Vec2  scale   = { 1.0, 1.0 };
	Vec2  vel     = {};
	float angle   = 0;

	CTransform() = default;

	CTransform(const Vec2& p)
		: pos(p), prevPos(p)
	{
	}

	CTransform(const Vec2& p, const Vec2& v, const Vec2& s, float a)
		: pos(p), prevPos(p), scale(s), vel(v), angle(a)
	{
	}
};

class CBoundingBox : public Component
{
public:
	Vec2 size     = {};
	Vec2 halfSize = {};

	CBoundingBox() = default;

	CBoundingBox(const Vec2& s)
		: size(s), halfSize(Vec2(s.x / 2, s.y / 2))
	{
	}
};

class CInput : public Component
{
public:
	bool up       = false;
	bool down     = false;
	bool left     = false;
	bool right    = false;
	bool shoot    = false;
	bool canShoot = true;
	bool canJump  = true;

	CInput()
	{
	};
};

class CAnimation : public Component
{
public:
	Animation animation;
	bool      repeat = false;

	CAnimation() = default;

	CAnimation(const Animation& animation, bool r)
		: animation(animation), repeat(r)
	{
	}
};

class CGravity : public Component
{
public:
	float gravity = 0;

	CGravity() = default;

	CGravity(float g)
		: gravity(g)
	{
	}
};

class CState : public Component
{
public:
	std::string state;

	CState() = default;

	CState(const std::string& s)
		: state(s)
	{
	}
};





