#pragma once
#include <vector>
#include <fstream>
#include <string>
#include "Point.h"
#include "ErrorCode.h"
#include "IFile.h"

class BinFile :public IFile
{
private:
	std::fstream Plik;
	Point Punkt;
public:
	BinFile(void);
	~BinFile(void);
	virtual ERROR_CODE read(std::vector<Point>& vec);
	virtual ERROR_CODE read(Point& pkt, int indeks);
	virtual ERROR_CODE write(std::vector<Point>& vec);
};

