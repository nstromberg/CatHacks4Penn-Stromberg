#include "lunchwidgetitem.h"
#include "ui_lunchwidgetitem.h"

LunchWidgetItem::LunchWidgetItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LunchWidgetItem)
{
    ui->setupUi(this);
}

LunchWidgetItem::~LunchWidgetItem()
{
    delete ui;
}
