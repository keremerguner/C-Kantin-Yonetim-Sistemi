#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include "Yonetim.h"
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

void menu()
{
	cout << "\n---Kantin Yonetim Sistemi---\n\n"
		 << endl;
	cout << "1-] Urun Ekle"
		 << endl
		 << "2-] Urun Sil"
		 << endl
		 << "3-] Urunleri Goruntule" << endl
		 << "9-] Exit" << endl;
}

int main()
{
	int newSelection = 0;
	KantinYonetim kantinYonetim;

	menu();

	while (true)
	{
	restart:
		kantinYonetim.fillVector(kantinYonetim.yonetimVector);

		cout << "\n\n"
			 << "Seciminizi Giriniz :  ";
		cin >> newSelection;
		
		system("cls");
		
		menu();
		
		switch (newSelection)
		{
		case 1:
			kantinYonetim.urunEkle(kantinYonetim.yonetimVector);
			kantinYonetim.yonetimVector.clear();
			goto restart;
		case 2:
			kantinYonetim.urunSil(kantinYonetim.yonetimVector);
			kantinYonetim.yonetimVector.clear();
			goto restart;
		case 3:
			kantinYonetim.urunGoruntule(kantinYonetim.yonetimVector);
			kantinYonetim.yonetimVector.clear();
			goto restart;
		case 9:
			break;
		default:
			cout << "\n\t\t"
			 << "Secim Bulunamadi !" << endl;
			goto restart;
		}
		break;

	}

	return 0;
}




