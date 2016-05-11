#include "mainwindow.h"

#include <QtGui>

#include "polje.h"
#include "tabla.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setWindowTitle(tr("Potapanje brodova  %1 ZI 2016").arg(QString(0xA9)));

    setupActions();
    setupMenus();

    qsrand(QTime::currentTime().msec());

    tabla = new Tabla(this);
    setCentralWidget(tabla);
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupActions()
{
    fileNew = new QAction(tr("&Nova igra"), this);
    fileNew->setShortcut(QKeySequence::New);
    connect(fileNew, SIGNAL(triggered()), this, SLOT(fileNewOnClick()));

    fileExit = new QAction(tr("&Izlaz"), this);
    fileExit->setShortcut(tr("Ctrl+Q"));
    connect(fileExit, SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::setupMenus()
{
    file = menuBar()->addMenu(tr("&Fajl"));
    file->addAction(fileNew);
    file->addSeparator();
    file->addAction(fileExit);
}

void MainWindow::fileNewOnClick()
{
    tabla->newGame();
}
