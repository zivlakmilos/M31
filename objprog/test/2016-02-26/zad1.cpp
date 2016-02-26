/*
 * Zadatak 1
 *  Npisati program koji ucitava grupu za engleski jezik.
 *  Grupa sadrzi pet clanova i o njima podatke:
 *      ime
 *      prezime
 *      godina
 *  Sortirati grupu po godinama
 */

#include <iostream>

using namespace std;

int main(void)
{
    struct clan
    {
        string ime;
        string prezime;
        int godina;
    };

    clan c[5], t;
    int i, j;

    cout << "Ime Prezime Godina" << endl;
    for(i = 0; i < 5; i++)
        cin >> c[i].ime >> c[i].prezime >> c[i].godina;

    for(i = 0; i < 5; i++)
        for(j = i + 1; j < 5; j++)
            if(c[i].godina > c[j].godina)
            {
                t = c[i];
                c[i] = c[j];
                c[j] = t;
            }

    cout << "Ime Prezime Godina" << endl;
    for(i = 0; i < 5; i++)
        cout << c[i].ime << " " << c[i].prezime << " " << c[i].godina << " " << endl;

    return 0;
}
