#pragma once

#include <cmath>
#include <easyx.h>


// 2D œÚ¡ø¿‡
class Vector2
{
public:
	double x;
	double y;

public:
	Vector2(double x = 0, double y = 0) : x(x), y(y) {}
	Vector2(POINT pos): x(pos.x), y(pos.y) {}

	operator POINT() const
	{
		return { (int)x, (int)y };
	}

	Vector2 operator+(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	void operator+=(const Vector2 & other)
	{
		x += other.x;
		y += other.y;
	}

	Vector2 operator-(const Vector2& other) const
	{
		return Vector2(x - other.x, y - other.y);
	}

	void operator-=(const Vector2 & other)
	{
		x -= other.x;
		y -= other.y;
	}

	double operator*(const Vector2& other) const
	{
		return x * other.x + y * other.y;
	}

	Vector2 operator*(double scalar) const
	{
		return Vector2(x * scalar, y * scalar);
	}

	void operator*=(double scalar)
	{
		x *= scalar;
		y *= scalar;
	}

	double length() const
	{
		return std::sqrt(x * x + y * y);
	}

	Vector2 normalize() const
	{
		double len = length();

		if (len == 0)
		{
			return Vector2(0, 0);
		}

		return Vector2(x / len, y / len);
	}

};

