

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include"Liste.hpp"
using namespace std;

class textFile
{
public:

    BListe liste = BListe();

    void readTextFile()
    {


        inFile.open("Veri.txt");
        if (!inFile) {
            cout << "Unable to open file";
            exit(1); // terminate with error
        }

        while (getline(inFile, command))
        {
            test = false;
            testIndex = false;


            


            if (command[0] == 'e' || command[0] == 'E')
            {
                for(int j=0;j<command.size();j++)
                    if (command[j] == '#')
                        testIndex = true;
                
                

                i = 2;
                while (command[i] != '#' && testIndex)
                {
                    indexTemp = indexTemp + command[i];
                    i++;
                }

                if (indexTemp == "")
                {
                    test = true;
                    indexTemp = "0";
                }

                index = stoi(indexTemp);
                
                

                while (command[i] != ')')
                {
                    if (command[i] == '#')
                        i++;
                    temp = temp + command[i];
                    i++;
                }

                veri = temp;

                if (test)
                {
                    liste.ekle(veri);
                }
                else
                {
                    liste.ekle(index, veri);
                }

                i = 0;
                temp = "";
                indexTemp = "";

            }
            else if (command[0] == 's' || command[0] == 'S')
            {
                i = 2;
                while (command[i] != ')')
                {
                    indexTemp = indexTemp + command[i];
                    i++;
                }

                if (indexTemp == "")
                {
                    test = true;
                    indexTemp = "0";
                }

                index = stoi(indexTemp);
               
               
                if (test)
                {
                    liste.cikar();
                }
                else
                {
                    liste.cikar(index);
                }
                i = 0;
                temp = "";
                indexTemp = "";

            }
            else
            {
                cout << "Wrong input form" << endl;
            }
        }

        liste.dugumYazdir();
        inFile.close();
        
    }



private:
    int index, i;
    string command,temp, indexTemp, veri;
    bool test ,testIndex;
    ifstream inFile;
};


