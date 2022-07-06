#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Point.h"
#include "ErrorCode.h"
#include "IFile.h"

class CsvFile :public IFile
{
private:
	std::fstream Plik;
	Point Punkt;
public:
	CsvFile(void);
	~CsvFile(void);
	virtual ERROR_CODE read(std::vector<Point>& wek);
	virtual ERROR_CODE read(Point& pkt, int indeks);
	virtual ERROR_CODE write(std::vector<Point>& wek);
};

