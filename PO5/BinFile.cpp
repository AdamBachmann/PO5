#include "BinFile.h"

using namespace std;

BinFile::BinFile(void)
{
	Plik.open("BinFile.bin", ios::in | ios::out | ios::app);
}

BinFile::~BinFile(void)
{
	Plik.close();
}

ERROR_CODE BinFile::read(std::vector<Point>& wek)
{
	string Linia;
	int u32DataCounter = 1;
	while (getline(Plik, Linia, ','))
	{
		if (u32DataCounter % 3 == 1)
			Punkt.setX(stof(Linia));
		else if (u32DataCounter % 3 == 2)
			Punkt.setY(stof(Linia));
		else
		{
			Punkt.setZ(stof(Linia));
			wek.push_back(Punkt);
		}
		u32DataCounter++;
	}

	return ERROR_CODE::OK;
}

ERROR_CODE BinFile::read(Point& pkt, int indeks)
{
	string Linia;
	int licznikDanych = 1;
	int licznikLini = 0;
	while (getline(Plik, Linia, ','))
	{
		if (licznikLini == indeks)
			break;

		if (licznikDanych % 3 == 1)
			pkt.setX(stof(Linia));
		else if (licznikDanych % 3 == 2)
			pkt.setY(stof(Linia));
		else
		{
			pkt.setZ(stof(Linia));
			licznikLini++;
		}
		licznikDanych++;
	}
	return ERROR_CODE::OK;
}

ERROR_CODE BinFile::write(std::vector<Point>& wek)
{
	for (int i = 0; i < wek.size(); i++)
	{
		Plik << wek[i].getX() << wek[i].getY() << wek[i].getZ();
	}
	return ERROR_CODE::OK;
}