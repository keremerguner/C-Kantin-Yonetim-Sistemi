#include <iostream>
#include <string>

using namespace std;

class Yonetim
{
private:
	string isim;
	string id;
	string fiyat;

public:
	Yonetim(string, string, string);

	void setIsim(string);
	//
	string getIsim() const;
	//
	void setId(string);
	//
	string getId() const;
	//
	void setFiyat(string);
	//
	string getFiyat() const;
};

Yonetim::Yonetim(string urunIsim, string urunId, string urunFiyat)
{
	isim = urunIsim;
	id = urunId;
	fiyat = urunFiyat;
}

string Yonetim::getIsim() const
{
	return isim;
}

string Yonetim::getId() const
{
	return id;
}

string Yonetim::getFiyat() const
{
	return fiyat;
}

void Yonetim::setIsim(string urunIsim)
{
	isim = urunIsim;
}

void Yonetim::setId(string urunId)
{
	id = urunId;
}

void Yonetim::setFiyat(string urunFiyat)
{
	fiyat = urunFiyat;
}
