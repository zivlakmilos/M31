/*
 * Zadatak 2
 *  u datoteku radnici.txt upisati
 *  imena, prezimena i plate 10 radinika
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    struct radnik
    {
        string ime;
        string prezime;
        float plata;
    };

    int i;
    radnik r[10];
    ofstream file("radnici.txt");

    if(file.is_open())
    {
        for(i = 0; i < 10; i++)
        {
            cout << i + 1 << ". radnik" << endl;
            cout << "Ime: ";
            cin >> r[i].ime;
            cout << "Prezime: ";
            cin >> r[i].prezime;
            cout << "Plata: ";
            cin >> r[i].plata;
        }

        for(i = 0; i < 10; i++)
            file << r[i].ime << endl
                 << r[i].prezime << endl
                 << r[i].plata << endl;
    } else
    {
        cout << "Nije moguce pisati u fajl!" << endl;
    }

    return 0;
}
