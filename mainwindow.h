#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

class QAction;
class QActionGroup;
class QMenu;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    void createMenus();
    void createActions();
    ~MainWindow();
private slots:
    void open();
private:
    QMenu *fileMenu;
    QAction * openAct;
};

#endif // MAINWINDOW_H
