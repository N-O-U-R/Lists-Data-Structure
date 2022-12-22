/**
* @file				Dugum.hpp
* @description		iki yönlü Bağıl Liste.
* @course			1B-12
* @assignment		1
* @date				8/11/2021
* @author			MHD NOUR ALKHALAF
*/

#include<iostream>
#include<iomanip>

using namespace std;

class Dugum
{
public:
	Dugum(string veri)
	{
		this->veri = veri;
		sonraki = onceki = 0;
	}

	Dugum* sonraki;
	Dugum* onceki;
	string veri;


};