#ifndef BROD_H
#define BROD_H


class Brod
{
public:
    Brod(int x, int y, int duzina, int pravac);
    ~Brod();

    void ubij();

    int getX() { return x; }
    int getY() { return y; }
    int getDuzina() { return duzina; }
    int getPravac() { return pravac; }
    void setX(int value) { x = value; }
    void setY(int value) { y = value; }
    void setPravac(int value) { pravac = value; }
    bool isZiv() { return ziv; }

    enum { Horizontalno = 0, Vertikalno };

private:
    int x;
    int y;
    int duzina;
    int pravac;
    bool ziv;
};

#endif // BROD_H
