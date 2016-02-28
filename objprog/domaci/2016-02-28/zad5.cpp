/*
 * Zadatak 5:
 *  Uneti podatke za n klubava
 *  (naziv, stadion i bodove)
 *  zatim sortirati po bodovima
 */

#include <iostream>

using namespace std;

int main(void)
{
    struct klub
    {
        string naziv;
        string stadion;
        int bodovi;
    };

    int n;
    int i, j;

    cout << "Broj klubova: ";
    cin >> n;

    klub niz[n];
    klub tmp;

    for(i = 0; i < n; i++)
    {
        cout << i + 1 << ". klub" <<endl;
        cout << "Naziv: ";
        cin >> niz[i].naziv;
        cout << "Stadion: ";
        cin >> niz[i].stadion;
        cout << "Broj bodova: ";
        cin >> niz[i].bodovi;
        cout << "=====================================" << endl;
    }

    for(i = 0; i < n; i++)
        for(j = i + 1; j < n; j++)
            if(niz[i].bodovi < niz[j].bodovi)
            {
                tmp = niz[i];
                niz[i] = niz[j];
                niz[j] = tmp;
            }

    cout << "===================================" << endl;

    for(i = 0; i < n; i++)
    {
        cout << "Naziv: " << niz[i].naziv << endl;
        cout << "Stadion: " << niz[i].stadion << endl;
        cout << "Bodovi: " << niz[i].bodovi << endl;
        cout << "===================================" << endl;
    }

    return 0;
}
