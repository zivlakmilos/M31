/*
 * Zadatak 1
 *  Napisati program koji u fajl ispisuje abecedu velikim slovima
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv)
{
    char c;
    ofstream file ("abeceda.txt");

    if(file.is_open())
    {
        for(c = 'A'; c <= 'Z'; c++)
        {
            file << c << ' ';
        }
    }

    file.close();

    return 0;
}
