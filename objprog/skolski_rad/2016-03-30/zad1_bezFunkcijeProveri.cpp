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

int Racunar::razmisli(char (*mapa)[3])
{
    int i, j, k;
    int pozicija = -1;  // Pozicija gde da se postavi O
    int tip = 10;       // Za prioritet kombinacija
    int tmp;            // Pomocna za racun

    for(i = 0; i < 3; i++)              // Redovi / Kolone
        for(j = 0; j < 3; j++)          // Kolone / Redovi
        {
            for(k = 0; k < 3; k++)      // Ostali u redu/koloni
            {
                if(j == k)
                    continue;
                if(mapa[i][j] == mapa[i][k])    // Redovi
                {
                    tmp = 3 - (j + k);          // Pomocna za kolonu
                    if(mapa[i][j] == 'O' && mapa[i][tmp] != 'X')
                        return i * 3 + tmp + 1;
                    else if(mapa[i][j] == 'X' && mapa[i][tmp] != 'O')
                    {
                        tip = 1;
                        pozicija = i * 3 + tmp + 1;
                    }
                }
                if(mapa[j][i] == mapa[k][i])    // Kolone
                {
                    tmp = 3 - (j + k);          // Pomocna za red
                    if(mapa[j][i] == 'O' && mapa[tmp][i] != 'X')
                        return tmp * 3 + i + 1;     // Najveci prioritet
                    else if(mapa[j][i] == 'X' && mapa[tmp][i] != 'O')
                    {
                        tip = 1;
                        pozicija = tmp * 3 + i + 1;
                    }
                }
            }
            if(i == j)
                continue;
            if(mapa[i][i] == mapa[j][j])            // Dijegonala (glavna)
            {
                tmp = 3 - (i + j);
                if(mapa[i][i] == 'O' && mapa[tmp][tmp] != 'X')
                    return tmp * 3 + tmp + 1;       // Najveci prioritet
                else if(mapa[i][i] == 'X' && mapa[tmp][tmp] != 'O')
                {
                    tip = 1;
                    pozicija = tmp * 3 + tmp + 1;
                }
            }
            int i1 = 2 - i;                         // Za pomocnu dijegonalu
            int j1 = 2 - j;                         // umesto glavne
            if(mapa[i][i1] == mapa[j][j1])          // Dijgonala (pomocna)
            {
                tmp = 3 - (i + j);
                int tmp1 = 2 - tmp;                 // Za pomocnu dijegonalu
                if(mapa[i][i1] == 'O' && mapa[tmp][tmp1] != 'X')
                    return tmp * 3 + tmp1 + 1;       // Najveci prioritet
                else if(mapa[i1][i1] == 'X' && mapa[tmp][tmp1] != 'O')
                {
                    tip = 1;
                    pozicija = tmp * 3 + tmp + 1;
                }
            }
        }

    return pozicija;
}
