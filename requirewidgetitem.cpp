#include "requirewidgetitem.h"
#include "ui_requirewidgetitem.h"

RequireWidgetItem::RequireWidgetItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RequireWidgetItem)
{
    ui->setupUi(this);
}

RequireWidgetItem::~RequireWidgetItem()
{
    delete ui;
}
