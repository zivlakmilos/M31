#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Tabla;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QAction *fileNew;
    QAction *fileExit;
    QMenu *file;
    Tabla *tabla;

    void setupActions();
    void setupMenus();

private slots:
    void fileNewOnClick();
};

#endif // MAINWINDOW_H
