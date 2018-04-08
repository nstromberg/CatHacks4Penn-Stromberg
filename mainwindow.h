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
    std::map<std::string,std::vector<std::vector<int>>> getItems();

private slots:

    void on_addPrefButton_clicked();

    void on_calcButton_clicked();

    void on_searchBox_returnPressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
