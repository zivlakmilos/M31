/*
 * Zadatak 1:
 *  napraviti igru XO
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class Racunar
{
    private:
        enum { BROJ_TIPOVA = 10 };

        /* Definicija je komentarisana */
        bool proveri(char (*mapa)[3],
                int x1, int y1,
                int x2, int y2,
                int x3, int y3,
                int *tip, int *pozicija);

    public:
        int razmisli(char (*mapa)[3]);
};

class Igra
{
    private:
        char mapa[3][3];
        bool aktivna;
        Racunar racunar;

    public:
        Igra(void);
        void crtaj(void);
        void unosPozicije(void);
        void racunarIgra(void);
        bool igraj(void) { return aktivna; };
        void setAktivna(bool aktivna) { this->aktivna = aktivna; }
};

int main(int argc, char *argv[])
{
    Igra igra;

    while(igra.igraj())
    {
        igra.crtaj();
        igra.unosPozicije();
        igra.racunarIgra();
    }

    return 0;
}

Igra::Igra(void)
{
    int i, j;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            mapa[i][j] = 0x30 + (i * 3 + j + 1);
    aktivna = true;
}

void Igra::crtaj(void)
{
    int i, j;

    system("clear");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
            cout << " " << mapa[i][j] << (j < 2 ? " |" : "");
        cout << endl;
        if(i < 2)
            cout << "---|---|---" << endl;
    }
}

void Igra::unosPozicije(void)
{
    char taster;            // Koja je tipka na tastaturi pritisnuta
    int pozicija;
    char znakNaPoziciji;

    do
    {
        taster = getchar();
        if(taster == 0x1B)      // ESC
        {
            aktivna = false;
            return;
        }
        pozicija = taster - 0x30;
        if(pozicija < 1 || pozicija > 9)
        {
            znakNaPoziciji = 'X';
            continue;
        }
        znakNaPoziciji = mapa[pozicija / 3][pozicija % 3 - 1];
    }
    while(znakNaPoziciji == 'X' || znakNaPoziciji == 'O');

    mapa[pozicija / 3][pozicija % 3 - 1] = 'O';
}

void Igra::racunarIgra(void)
{
    int pozicija = racunar.razmisli(mapa);
    if(pozicija > 0)
        mapa[pozicija / 3][pozicija % 3 - 1] = 'O';
}

/*
 * Malo cudna metoda pa je moram posebno komentarisati :)
 *  x1, y1 - za prvi if (x, y) koordinate (mapa[x][y])
 *  x2, y2 - za drugi if -||-
 *  x3, y3 - za treci if -||-
 *
 *  x1, y1 - prvo polje u nizu, zauzeto
 *  x2, y2 - drugo polje u nizu, zauzeto
 *  x3, y3 - slobodno polje
 *
 *
 *  tip i pozicija su iz funkcije koja poziva proveri (razmisli)
 *  to su pokazivaci, tako da se vrednost menja i u funkciji razmisli
 *
 *  vraca true ako je tip 1 (najviseg prioriteta), da ne trazi dalje
 *  zbog performansi algoritma
 *
 * malo je cudno, ali prvo je bilo sve u razmisli, a onda je kod predugacak
 */
bool Racunar::proveri(char (*mapa)[3],
        int x1, int y1,
        int x2, int y2,
        int x3, int y3,
        int *tip, int *pozicija)
{
    if(mapa[x1][y1] == mapa[x2][y2])
    {
        if(mapa[x1][y1] == 'O' && mapa[x3][y3] != 'X')
        {
            *pozicija = x3 * 3 + y3 + 1;
            return true;
        } else if(mapa[x1][y1] == 'X' && mapa[x3][y3] != 'O')
        {
            if(*tip > 1)
            {
                *tip = 1;
                *pozicija = x3 * 3 + y3 + 1;
            }
        }
    }
    return false;
}

int Racunar::razmisli(char (*mapa)[3])
{
    int i, j, k;
    int pozicija = -1;      // Pozicija gde da se postavi O
    int tip = BROJ_TIPOVA;  // Za prioritet kombinacija
    int tmp;                // Pomocna za racun

    for(i = 0; i < 3; i++)              // Redovi / Kolone
        for(j = 0; j < 3; j++)          // Kolone / Redovi
        {
            for(k = 0; k < 3; k++)      // Ostali u redu/koloni
            {
                if(j == k)
                    continue;
                tmp = 3 - (j + k);      // Pomocna za redove
                if(proveri(mapa, i, j, i, k, i, tmp, &tip, &pozicija)) // Redovi
                    return pozicija;
                tmp = 3 - (j + k);      // Pomocna za kolone
                if(proveri(mapa, j, i, k, i, tmp, i, &tip, &pozicija)) // Kolone
                    return pozicija;
            }
            if(i == j)
                continue;
            tmp = 3 - (i + j);
            if(proveri(mapa, i, i, j, j, tmp, tmp, &tip, &pozicija)) // Dijegonala (glavna)
                return pozicija;
            int i1 = 2 - i;             // Za pomocnu
            int j1 = 2 - j;             // dijegonalu
            int tmp1 = 2 - tmp;         // umesto glavne
            if(proveri(mapa, i, i1, j, j1, tmp, tmp1, &tip, &pozicija)) // Dijegonala (pomocna)
                return pozicija;
        }

    return pozicija;
}
