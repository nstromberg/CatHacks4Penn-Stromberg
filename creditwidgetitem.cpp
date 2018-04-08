#include "creditwidgetitem.h"
#include "ui_creditwidgetitem.h"

CreditWidgetItem::CreditWidgetItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreditWidgetItem)
{
    ui->setupUi(this);
}

CreditWidgetItem::~CreditWidgetItem()
{
    delete ui;
}
