#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "creditwidgetitem.h"
#include "avoidwidgetitem.h"
#include "requirewidgetitem.h"
#include "classwidgetitem.h"
#include "lunchwidgetitem.h"
#include <map>
#include <vector>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addPrefButton_clicked()
{
    QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget);
    ui->listWidget->addItem(listWidgetItem);
    QString selection = ui->comboBox->currentText();

    if(selection.contains("Credit"))
    {
        CreditWidgetItem *creditWidgetItem = new CreditWidgetItem;
        listWidgetItem->setSizeHint(creditWidgetItem->sizeHint());
        ui->listWidget->setItemWidget(listWidgetItem,creditWidgetItem);
    }
    else if(selection.contains("Class"))
    {
        ClassWidgetItem *classWidgetItem = new ClassWidgetItem;
        listWidgetItem->setSizeHint(classWidgetItem->sizeHint());
        ui->listWidget->setItemWidget(listWidgetItem,classWidgetItem);
    }
    else if(selection.contains("Lunch"))
    {
        LunchWidgetItem *lunchWidgetItem = new LunchWidgetItem;
        listWidgetItem->setSizeHint(lunchWidgetItem->sizeHint());
        ui->listWidget->setItemWidget(listWidgetItem,lunchWidgetItem);
    }
    else if(selection.contains("Avoid"))
    {
        AvoidWidgetItem *avoidWidgetItem = new AvoidWidgetItem;
        listWidgetItem->setSizeHint(avoidWidgetItem->sizeHint());
        ui->listWidget->setItemWidget(listWidgetItem,avoidWidgetItem);
    }
    else if(selection.contains("Require"))
    {
        RequireWidgetItem *requireWidgetItem = new RequireWidgetItem;
        listWidgetItem->setSizeHint(requireWidgetItem->sizeHint());
        ui->listWidget->setItemWidget(listWidgetItem,requireWidgetItem);
    }

}

std::map MainWindow::getItems()
{
    std::map<std::string,std::vector<int>> reqs;
    for(int i = 0; i<ui->listWidget->count(); i++){
        vector<int>
        reqs[ui->listWidget->indexWidget(i)->objectName()]
    }
}

