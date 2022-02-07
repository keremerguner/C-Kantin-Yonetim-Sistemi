#include <iostream>
#include "Urun.h"
#include <fstream>
#include <string>


using namespace std;

class KantinYonetim
{
public:
	vector<Yonetim> yonetimVector;

	void fillVector(vector<Yonetim> &yonetimVector);
	void urunEkle(vector<Yonetim> &yonetimVector);
	void urunGoruntule(vector<Yonetim> &yonetimVector);
	void urunSil(vector<Yonetim> &yonetimVector);
};

void KantinYonetim::fillVector(vector<Yonetim> &yonetimVector)
{
	string textData;
	string isim;
	string id;
	string fiyat;

	vector<string> temporary;

	fstream file;
	file.open("text.txt");

	while (getline(file, textData))
	{
		temporary.push_back(textData);
	}

	file.close();

	for (int i = 0; i < temporary.size(); i++)
	{
		isim = temporary[i];
		i += 1;
		//
		id = temporary[i];
		i += 1;
		//
		fiyat = temporary[i];
		//
		Yonetim newProduct(isim, id, fiyat);
		yonetimVector.push_back(newProduct);
	}
}

void KantinYonetim::urunEkle(vector<Yonetim> &yonetimVector)
{
	string isim;
	string id;
	string fiyat;

	cin.ignore();

	cout << "\n"
		 << "Urun Ismi Giriniz : ";
	getline(cin, isim);

	for (int i = 0; i < yonetimVector.size(); i++)
	{
		if (yonetimVector[i].getIsim() == isim)
		{
			cout << "\n"
				 << "Eklenmis bir seyi bir daha ekleyemezsiniz." << endl;
		}
	}

	cout << "\n"
		 << "Urun ID giriniz : ";
	cin >> id;

	for (int i = 0; i < yonetimVector.size(); i++)
	{
		if (yonetimVector[i].getId() == id)
		{
			cout << "\n"
				 << "Eklenmis bir seyi bir daha ekleyemezsiniz." << endl;
		}
	}

	cout << "\n"
		 << "Urun fiyatini giriniz : ";
	cin >> fiyat;

	Yonetim newProduct(isim, id, fiyat);

	fstream file;
	file.open("text.txt", ios::app);

	file << isim << endl;
	file << id << endl;
	file << fiyat << endl;
}

void KantinYonetim::urunGoruntule(vector<Yonetim> &yonetimVector)
{

	string isim;
	string id;
	string fiyat;

	cout << "\n\n\n"
		 << "" << endl;
	cout << "        ISIM"
		 << "\t\t\t"
		 << "ID"
		 << "\t\t\t"
		 << "STOK" << endl;
	cout << "" << endl;

	for (int i = 0; i < yonetimVector.size(); i++)
	{
		if (yonetimVector[i].getIsim().length() >= 10)
		{
			cout << "  " << i + 1 << "."
				 << " " << yonetimVector[i].getIsim();
			cout << "\t\t";
			cout << yonetimVector[i].getId();
			cout << "\t\t\t";
			cout << yonetimVector[i].getFiyat();
			cout << "\n";
		}

		else
		{
			cout << "  " << i + 1 << "."
				 << " " << yonetimVector[i].getIsim();
			cout << "\t\t\t";
			cout << yonetimVector[i].getId();
			cout << "\t\t\t";
			cout << yonetimVector[i].getFiyat();
			cout << "\n";
		}

		cout << endl;
	}

	cout << "" << endl;
}

void KantinYonetim::urunSil(vector<Yonetim> &yonetimVector)
{
	string isim;
	string id;
	string fiyat;

	bool counter = false;

	cin.ignore();

	cout << "\n\n"
		 << "Kaldirmak istedigin urun ISMI : ";
	getline(cin, isim);

	ifstream oldFile;
	oldFile.open("text.txt");

	ofstream newFile;
	newFile.open("text1.txt", ios::app);

	for (int i = 0; i < yonetimVector.size(); i++)
	{
		if (yonetimVector[i].getIsim() == isim)
		{
			counter = true;
		}

		else
		{
			newFile << yonetimVector[i].getIsim() << endl;
			newFile << yonetimVector[i].getId() << endl;
			newFile << yonetimVector[i].getFiyat() << endl;
		}
	}

	if (counter == false)
	{
		cout << "\n Urun Bulunamadi " << endl;
	}

	oldFile.close();
	newFile.close();

	remove("text.txt");
	rename("text1.txt", "text.txt");
}
