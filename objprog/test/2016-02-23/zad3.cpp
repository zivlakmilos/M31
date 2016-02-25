/*
 * Procitati broj ucenika iz m31.txt
 *  (26)
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    int brUcenika;
    ifstream m31("m31.txt");

    if(m31.is_open())
    {
        m31 >> brUcenika;
        cout << "U odeljenju m31 ima: " << brUcenika << " ucenika" << endl;
    } else
    {
        cout << "Nije moguce otvoriti fajl" << endl;
    }

    m31.close();

    return 0;
}
