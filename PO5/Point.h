#pragma once
class Point
{
private:
	float x;
	float y;
	float z;
public:
	Point(float f32dataX = 0, float f32dataY = 0, float f32dataZ = 0);

	float getX();
	float getY();
	float getZ();

	void setX(float f32data);
	void setY(float f32data);
	void setZ(float f32data);
};

