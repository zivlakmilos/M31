#ifndef BROD_H
#define BROD_H


class Brod
{
public:
    Brod(int x, int y, int duzina, int pravac);
    ~Brod();

    int getX() { return x; }
    int getY() { return y; }
    int getDuzina() { return duzina; }
    int getPravac() { return pravac; }
    void setX(int value) { x = value; }
    void setY(int value) { y = value; }
    void setPravac(int value) { pravac = value; }

    enum { Horizontalno = 0, Vertikalno };

private:
    int x;
    int y;
    int duzina;
    int pravac;
};

#endif // BROD_H
