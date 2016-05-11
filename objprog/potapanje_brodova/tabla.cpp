#include "tabla.h"

#include <QtGui>

#include "polje.h"
#include "brod.h"

Tabla::Tabla(QWidget *parent)
    : QWidget(parent)
{
    for(int i = 0; i < DimenzijeTable; i++)
        for(int j = 0; j < DimenzijeTable; j++)
            polja[i][j] = new Polje(Polje::Prazno, this);

    setupLayout();
    newGame();
}

Tabla::~Tabla()
{
    for(int i = 0; i < DimenzijeTable; i++)
        for(int j = 0; j < DimenzijeTable; j++)
            delete polja[i][j];
    for(int i = 0; i < brodovi.size(); i++)
        delete brodovi[i];
}

void Tabla::setupLayout()
{
    mainLayout = new QGridLayout(this);
    mainLayout->setSpacing(1);

    for(int i = 0; i < DimenzijeTable; i++)
        for(int j = 0; j < DimenzijeTable; j++)
            mainLayout->addWidget(polja[i][j], i, j);
}

void Tabla::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(QRect(0, 0, width(), height()), Qt::black);
}

void Tabla::newGame()
{
    int x, y;
    int pravac;

    brojPokusaja = 0;

    for(int i = 0; i < brodovi.size(); i++)
        delete brodovi[i];
    brodovi.clear();
    for(int i = 1; i <= 4; i++)
    {
        for(int j = i; j <= 4; j++)
        {
            pravac = qrand() % 2;
            if(pravac == Brod::Horizontalno)
            {
                x = qrand() % (10 - i);
                y = qrand() % 10;
            } else
            {
                x = qrand() % 10;
                y = qrand() % (10 - i);
            }
            brodovi.push_back(new Brod(x, y, i, pravac));
        }
    }

    for(int i = 0; i < brodovi.size(); i++)
    {
        for(int j = 0; j < brodovi.size(); j++)
        {
            if(i == j)
                continue;
            for(int n = 0, m = 0; n < brodovi[i]->getDuzina() && m < brodovi[j]->getDuzina(); n++, m++)
            {
                int x1, y1;
                int x2, y2;
                x1 = brodovi[i]->getX();
                y1 = brodovi[i]->getY();
                x2 = brodovi[j]->getX();
                y2 = brodovi[j]->getY();
                if(brodovi[i]->getPravac() == Brod::Horizontalno)
                    x1 += n;
                else
                    y1 += n;
                if(brodovi[j]->getPravac() == Brod::Horizontalno)
                    x2 += n;
                else
                    y2 += m;

                if((x1 == x2 && y1 == y2))
                {
                    pravac = qrand() % 2;
                    if(pravac == Brod::Horizontalno)
                    {
                        x = qrand() % (10 - i);
                        y = qrand() % 10;
                    } else
                    {
                        x = qrand() % 10;
                        y = qrand() % (10 - i);
                    }
                    brodovi[j]->setX(x);
                    brodovi[j]->setY(y);
                    brodovi[j]->setPravac(pravac);
                    i = 0;
                    j = 0;
                    break;
                }
            }
        }
    }

    postaviMapu();
}

void Tabla::postaviMapu()
{
    for(int i = 0; i < DimenzijeTable; i++)
        for(int j = 0; j < DimenzijeTable; j++)
            polja[i][j]->setStatus(Polje::Prazno);

    QVector<Brod *>::iterator iterator;
    for(iterator = brodovi.begin(); iterator != brodovi.end(); iterator++)
    {
        int x = (*iterator)->getX();
        int y = (*iterator)->getY();
        for(int i = 0; i < (*iterator)->getDuzina(); i++)
        {
            polja[y][x]->setStatus(Polje::Brod_Ziv);
            if((*iterator)->getPravac() == Brod::Horizontalno)
                x++;
            else
                x++;
        }
    }
}

void Tabla::promenjenStatus()
{
    bool kraj = true;
    int x, y;
    int j;

    for(int i = 0; i < brodovi.size(); i++)
    {
        if(!brodovi[i]->isZiv())
            continue;
        brodovi[i]->getX();
        brodovi[i]->getY();
        for(j = 0; j < brodovi[i]->getDuzina(); j++)
        {
            if(polja[x][y]->getStatus() == Polje::Brod_Ziv)
                break;
            if(brodovi[i]->getPravac() == Brod::Horizontalno)
                x++;
            else
                y++;
        }
        if(j >= brodovi[i]->getDuzina())
            brodovi[i]->ubij();
        else
            kraj = false;
    }

    if(kraj)
    {
        if(QMessageBox::information(this, tr("Potapanje brodova"),
                                    tr("Igra uspesno zavrsena sa %1 pokusaja!"
                                        "Da li zelite da pokrenete novu igru?").arg(brojPokusaja),
                                    QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
        {
            newGame();
        }
    }
}

