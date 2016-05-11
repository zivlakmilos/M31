#include "brod.h"

Brod::Brod(int x, int y, int duzina, int pravac)
{
    this->x = x;
    this->y = y;
    this->duzina = duzina;
    this->pravac = pravac;
    ziv = true;
}

Brod::~Brod()
{
}

void Brod::ubij()
{
    ziv = false;
}

