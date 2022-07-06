#include "Point.h"

Point::Point(float f32dataX, float f32dataY, float f32dataZ)
{
	x = f32dataX;
	y = f32dataY;
	z = f32dataZ;
}

float Point::getX()
{
	return x;
}

float Point::getY()
{
	return y;
}

float Point::getZ()
{
	return z;
}

void Point::setX(float f32data)
{
	x = f32data;
}

void Point::setY(float f32data)
{
	y = f32data;
}

void Point::setZ(float f32data)
{
	z = f32data;
}