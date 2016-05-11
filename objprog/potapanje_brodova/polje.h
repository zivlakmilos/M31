#ifndef POLJE_H
#define POLJE_H

#include <QWidget>

class Polje : public QWidget
{
    Q_OBJECT

public:
    Polje(int status = Prazno, QWidget *parent = 0);
    ~Polje();

    QSize sizeHint() const;
    int getStatus() { return status; }
    void setStatus(int value) { status = value; promeniSliku(value); }

    enum { Prazno = 0, Brod_Ziv, Brod_Pogodjen, Promasaj };

private:
    QImage slika;
    int status;

protected:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

signals:
    void promenjenStatus(int status);

private slots:
    void promeniSliku(int status);
};

#endif // POLJE_H
