/**
* @file				Liste.hpp
* @description		iki yönlü Bağıl Liste.
* @course			1B-12
* @assignment		1
* @date				8/11/2021
* @author			MHD NOUR ALKHALAF
*/


#include "Dugum.hpp"

class BListe
{
public:
	BListe()
	{
		ilk = 0;
		dugumSayisi = 0;
	}
	~BListe()
	{
		Dugum* temp = ilk;

		for (int i = 0; i < dugumSayisi; i++)
		{
			Dugum* silinecek = temp;

			temp = temp->sonraki;
			delete silinecek;
		}
	}
	void dugumYazdir()
	{
		Dugum* temp = ilk;
		cout << "\n\nResult:\n\n\n";
		while (temp->sonraki != 0)
		{
			cout << temp->veri << " <-> ";

			temp = temp->sonraki;
		}
		cout << temp->veri;

	}


	void ekle(int index,string veri)
	{
		if (index == 0 && ilk == 0)
		{
			ilk = new Dugum(veri);
			dugumSayisi++;
		}
		else if (index >= dugumSayisi)
		{
			ekle(veri);
		}
		else
		{
			

			Dugum* yeniDugum = dugumGetir(index);

			if (yeniDugum == 0)
				return;

			Dugum* yeni = new Dugum(veri);
			Dugum* yeniOnceki = yeniDugum->onceki;

			yeniDugum->onceki = yeni;
			yeni->sonraki = yeniDugum;
			yeni->onceki = yeniOnceki;

			if (yeniOnceki)
				yeniOnceki->sonraki = yeni;
			else
				ilk = yeni;
			dugumSayisi++;
			
		}
		
	}
	void ekle(string veri)
	{
		Dugum* yeni = new Dugum(veri);

		if (ilk == 0)
		{
			ilk = yeni;
		}
		else
		{
			Dugum* temp = ilk;

			while (temp->sonraki != 0)
				temp = temp->sonraki;

			temp->sonraki = yeni;
			yeni->onceki = temp;
		}


		dugumSayisi++;


	}

	void cikar(int index)
	{

		Dugum* silinecek = dugumGetir(index);

		if (index >= dugumSayisi && dugumSayisi > 0)
		{
			cikar();
			return;
		}
		else if (silinecek == 0)
		{
			return;
		}
		else
		{

			Dugum* yeniOnceki = silinecek->onceki;
			Dugum* yeniSonraki = silinecek->sonraki;

			delete silinecek;

			if (yeniSonraki)
				yeniSonraki->onceki = yeniOnceki;
			if (yeniOnceki)
				yeniOnceki->sonraki = yeniSonraki;
			else
				ilk = yeniSonraki;

			dugumSayisi--;
		}

	}

	void cikar()
	{
		if (ilk == 0)
			return;

		if (ilk->sonraki == 0)
		{
			delete ilk;
			ilk = 0;
		}
		else
		{
			Dugum* temp = sondanBirOncekiGetir();

			delete temp->sonraki;
			temp->sonraki = 0;
		}

		dugumSayisi--;
	}
	



private:
	Dugum* sondanBirOncekiGetir()
	{
		if (ilk == 0)
			return 0;
		if (ilk->sonraki == 0)
			return ilk;

		Dugum* temp = ilk;
		while (temp->sonraki->sonraki != 0)
			temp = temp->sonraki;

		return temp;
	}

	Dugum* dugumGetir(int index)
	{
		if (index < 0 || index >= dugumSayisi)
			return 0;

		Dugum* gec = ilk;

		for (int i = 0; i < index; i++)
		{
			gec = gec->sonraki;
		}
		return gec;
	}

	Dugum* ilk;
	int dugumSayisi;

};