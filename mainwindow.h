#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "requirewidgetitem.h"
#include "avoidwidgetitem.h"
#include "lunchwidgetitem.h"
#include "creditwidgetitem.h"
#include "classwidgetitem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    getNames(std::string[] items);
    getValues(std)

private slots:

    void on_addPrefButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
