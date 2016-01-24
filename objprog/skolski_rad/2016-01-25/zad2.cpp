/*
 * Zad2:
 *  Napraviti strukturu ucenik sa poljima ima, prezime i prosek
 *  odstampati ucenika sa vecim prosekom i razliku proseka
 *
 *  (ja sam prositio za n)
 */

#include <iostream>

using namespace std;

typedef struct
{
    char ime[30];
    char prezime[30];
    float prosek;
} Ucenik;

int main(int argc, char *argv[])
{
    int i;
    int najveci = 0;
    int drugi = 1;
    int brUcenika;

    cout << "Unesi broj ucenika: ";
    cin >> brUcenika;
    Ucenik ucenik[brUcenika];

    cout << endl;
    for(i = 0; i < brUcenika; i++)
    {
        cout << "Ime: ";
        cin >> ucenik[i].ime;
        cout << "Prezime: ";
        cin >> ucenik[i].prezime;
        cout << "Prosek: ";
        cin >> ucenik[i].prosek;
    }

    for(i = 0; i < brUcenika; i++)
        if(ucenik[i].prosek > ucenik[najveci].prosek)
        {
            drugi = najveci;
            najveci = i;
        }

    cout << endl;
    cout << "Ime: " << ucenik[najveci].ime << endl;
    cout << "Prezime: " << ucenik[najveci].prezime << endl;
    cout << "Prosek: " << ucenik[najveci].prosek << endl;
    cout << "Razlika izmedju 1. i 2.: " << ucenik[najveci].prosek - ucenik[drugi].prosek << endl;

    return 0;
}
