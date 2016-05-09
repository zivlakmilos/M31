#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void setupActions();
    void setupMenus();

private slots:
};

#endif // MAINWINDOW_H
