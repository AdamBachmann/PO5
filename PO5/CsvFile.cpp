#include "CsvFile.h"

using namespace std;

CsvFile::CsvFile(void)
{
	Plik.open("CsvFile.csv", ios::in | ios::out | ios::app);
}

CsvFile::~CsvFile(void)
{
	Plik.close();
}

ERROR_CODE CsvFile::read(std::vector<Point>& wek)
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

ERROR_CODE CsvFile::read(Point& pkt, int indeks)
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

ERROR_CODE CsvFile::write(std::vector<Point>& wek)
{
	for (int i = 0; i < wek.size(); i++)
	{
		Plik << wek[i].getX() << "," << wek[i].getY() << "," << wek[i].getZ() << "," << endl;
	}
	return ERROR_CODE::OK;
}