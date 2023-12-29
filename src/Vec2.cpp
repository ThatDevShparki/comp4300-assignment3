#include "Vec2.h"
#include <cmath>


Vec2::Vec2() = default;

Vec2::Vec2(float xin, float yin)
	: x(xin), y(yin)
{
}

bool Vec2::operator ==(const Vec2& rhs) const
{
	return x == rhs.x && y == rhs.y;
}

bool Vec2::operator !=(const Vec2& rhs) const
{
	return x != rhs.x || y != rhs.y;
}

Vec2 Vec2::operator +(const Vec2& rhs) const
{
	return { x + rhs.x, y + rhs.y };
}

Vec2 Vec2::operator -(const Vec2& rhs) const
{
	return { x - rhs.x, y - rhs.y };
}

Vec2 Vec2::operator *(float rhs) const
{
	return { x * rhs, y * rhs };
}

Vec2 Vec2::operator /(float rhs) const
{
	return { x / rhs, y / rhs };
}

void Vec2::operator +=(const Vec2& rhs)
{
	x += rhs.x;
	y += rhs.y;
}

void Vec2::operator -=(const Vec2& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
}

void Vec2::operator *=(float rhs)
{
	x *= rhs;
	y *= rhs;
}

void Vec2::operator /=(float rhs)
{
	x /= rhs;
	y /= rhs;
}

[[nodiscard]] float Vec2::mag() const
{
	return sqrtf(powf(x, 2) + powf(y, 2));
}

[[nodiscard]] Vec2 Vec2::norm() const
{
	return *this / mag();
}

[[nodiscard]] float Vec2::dist(const Vec2& rhs) const
{
	return (*this - rhs).mag();
}