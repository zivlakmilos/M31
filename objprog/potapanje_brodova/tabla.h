#ifndef TABLA_H
#define TABLA_H

#include <QWidget>

class QGridLayout;
class Brod;
class Polje;

class Tabla : public QWidget
{
    Q_OBJECT

public:
    Tabla(QWidget *parent = 0);
    ~Tabla();

    void newGame();

    enum { DimenzijeTable = 10 };

private:
    QGridLayout *mainLayout;
    QVector<Brod *> brodovi;
    Polje *polja[DimenzijeTable][DimenzijeTable];

    void setupLayout();
    void postaviMapu();

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // TABLA_H
