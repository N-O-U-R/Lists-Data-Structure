
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
