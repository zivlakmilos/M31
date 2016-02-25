/*
 * Zadatak 1
 *  Ucitati podatke o stedisama banke
 *  ime, prezime, tekuci racun i iznos na racunu.
 *  Broj racuna je integer koji ima 8 znakova.
 *  Uneti podatke za 7 stedisa i sortirati po visini uloga
 */

#include <iostream>

using namespace std;

int main(void)
{
    struct stedisa                      // Po tekstu zadatka
    {
        string ime;
        string prezime;
        int tekuciRacun;
        float stanjeRacuna;
    };

    stedisa s[7];                       // Niz stedisa (struktura)
    int i, j;                           // Brojaci
    stedisa tmp;                        // Pomocna, za sortiranje

    /*
     * Ucitavanje
     */

    for(i = 0; i < 7; i++)
    {
        cout << "Ime: ";
        cin >> s[i].ime;
        cout << "Prezime: ";
        cin >> s[i].prezime;
        cout << "Broj racuna: ";
        cin >> s[i].tekuciRacun;
        cout << "Stanje na racunu: ";
        cin >> s[i].stanjeRacuna;
    }

    /*
     * Sortiranje
     */

    for(i = 0; i < 7; i++)
        for(j = i + 1; j < 7; j++)
            if(s[i].stanjeRacuna < s[j].stanjeRacuna)
            {
                tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }

    /*
     * Ispis
     */

    for(i = 0; i < 7; i++)
    {
        cout << "Ime: " << s[i].ime << endl;
        cout << "Prezime: " << s[i].prezime << endl;
        cout << "Broj racuna: " << s[i].tekuciRacun << endl;
        cout << "Stanje na racunu: " << s[i].stanjeRacuna << endl;
    }

    return 0;
}
