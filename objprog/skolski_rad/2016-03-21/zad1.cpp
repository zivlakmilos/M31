/*
 * Uneti dva broja, proslediti ih klasi koja proverava deljivost
 */

#include <iostream>

using namespace std;

class Deljivost
{
    public:
        static int deljiv(int broj, int delilac);
};

int main(int argc, char *argv[])
{
    int deljenik, delilac;
    cin >> deljenik;
    cin >> delilac;

    if(Deljivost::deljiv(deljenik, delilac))
        cout << "Deljiv je" << endl;
    else
        cout << "Nije deljiv" << endl;

    return 0;
}

int Deljivost::deljiv(int broj, int delilac)
{
    while((broj -= delilac) > 0);
    if(broj == 0)
        return 1;
    else
        return 0;
}
