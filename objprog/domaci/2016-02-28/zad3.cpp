/*
 * Zadatak 3:
 *  Ucitati dva broja i njihv zbir sacuvati
 *  u fajl koji korisnik navede.
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    int broj1, broj2;
    char fileName[50];

    cout << "Prvi broj: ";
    cin >> broj1;
    cout << "Drugi broj: ";
    cin >> broj2;
    cout << "Naziv fajla: ";
    cin >> fileName;

    ofstream file(fileName);

    if(file.is_open())
    {
        file << broj1 + broj2;
    } else
        cout << "Nije moguce pisati u fajl!" << endl;

    return 0;
}
