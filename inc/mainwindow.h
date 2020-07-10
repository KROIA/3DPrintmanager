#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "printjob.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    public slots:
        void displayJob(Printjob &job);

    private:
        Ui::MainWindow *ui;

        Printjob _printjob;
};

#endif // MAINWINDOW_H
