#pragma once
#include <vector>
#include <fstream>
#include "ErrorCode.h"
#include "Point.h"

class IFile
{
private:
	std::fstream Plik;
	Point Punkt;
public:
	virtual ERROR_CODE read	(std::vector<Point>& vec)	= 0;
	virtual ERROR_CODE read	(Point& pkt, int indeks)	= 0;
	virtual ERROR_CODE write(std::vector<Point>& vec)	= 0;
};