#ifndef CREDITWIDGETITEM_H
#define CREDITWIDGETITEM_H

#include <QWidget>

namespace Ui {
class CreditWidgetItem;
}

class CreditWidgetItem : public QWidget
{
    Q_OBJECT

public:
    explicit CreditWidgetItem(QWidget *parent = 0);
    ~CreditWidgetItem();

private:
    Ui::CreditWidgetItem *ui;
};

#endif // CREDITWIDGETITEM_H
