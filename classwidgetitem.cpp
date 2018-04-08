#include "classwidgetitem.h"
#include "ui_classwidgetitem.h"

ClassWidgetItem::ClassWidgetItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClassWidgetItem)
{
    ui->setupUi(this);
}

ClassWidgetItem::~ClassWidgetItem()
{
    delete ui;
}
