/*
 * Zadatak 1
 *  Uneti niz celih brojeva i u fajl
 *  upisati najmanji i najveci
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    int n;
    int i, j;
    int min, max;
    ofstream file("minmaks.txt");

    if(file.is_open())
    {
        cout << "Broj clanova niza: ";
        cin >> n;

        int niz[n];

        for(i = 0; i < n; i++)
        {
            cout << i + 1 << ". clan: ";
            cin >> niz[i];
        }

        min = niz[0];
        max = niz[0];

        for(i = 1; i < n; i++)
            if(niz[i] < min)
                min = niz[i];
            else if(niz[i] > max)
                max = niz[i];

        file << min << endl << max;
    } else
        cout << "Nije moguce pisati u fajl" << endl;

    return 0;
}
