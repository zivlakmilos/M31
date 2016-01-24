/*
 * Zad1:
 *  Napraviti i inicirati strukturu za datum
 *  zatim ispisati na standardni izlaz
 */

#include <iostream>

using namespace std;

typedef struct
{
    int dan;
    string mesec;
    int godina;
} Datum;

int main(int argc, char *argv[])
{
    Datum datum { 2, "Januar", 2016 };
    cout << datum.dan << ". " << datum.mesec << " " << datum.godina << "." << endl;

    return 0;
}
