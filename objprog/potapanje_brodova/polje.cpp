#include "polje.h"

#include <QtGui>

Polje::Polje(int status, QWidget *parent)
    : QWidget(parent)
{
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    this->status = status;
    promeniSliku(status);

    connect(this, SIGNAL(promenjenStatus(int)), this, SLOT(promeniSliku(int)));
}

Polje::~Polje()
{
}

void Polje::mousePressEvent(QMouseEvent *event)
{
    if(event->button() != Qt::LeftButton)
        return;

    if(status == Brod_Ziv)
    {
        status = Brod_Pogodjen;
        emit promenjenStatus(status);
    } else if(status == Prazno)
    {
        status = Promasaj;
        emit promenjenStatus(status);
    }
}

void Polje::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QTransform transform;
    float ratioX = width() / (float)slika.width();
    float ratioY = height() / (float)slika.height();
    transform.scale(ratioX, ratioY);
    painter.setTransform(transform);
    painter.drawPixmap(0, 0, QPixmap::fromImage(slika));
}

void Polje::promeniSliku(int status)
{
    if(status == Brod_Ziv)
        slika = QImage(tr(":/slike/%1.jpg").arg(Prazno));
    else
        slika = QImage(tr(":/slike/%1.jpg").arg(status));
    update();
}

QSize Polje::sizeHint() const
{
    return QSize(100, 100);
}

