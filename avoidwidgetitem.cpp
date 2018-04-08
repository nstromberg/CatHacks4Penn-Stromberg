#include "avoidwidgetitem.h"
#include "ui_avoidwidgetitem.h"

AvoidWidgetItem::AvoidWidgetItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AvoidWidgetItem)
{
    ui->setupUi(this);
}

AvoidWidgetItem::~AvoidWidgetItem()
{
    delete ui;
}
