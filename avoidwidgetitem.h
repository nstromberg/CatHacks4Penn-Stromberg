#ifndef AVOIDWIDGETITEM_H
#define AVOIDWIDGETITEM_H

#include <QWidget>

namespace Ui {
class AvoidWidgetItem;
}

class AvoidWidgetItem : public QWidget
{
    Q_OBJECT

public:
    explicit AvoidWidgetItem(QWidget *parent = 0);
    ~AvoidWidgetItem();

private:
    Ui::AvoidWidgetItem *ui;
};

#endif // AVOIDWIDGETITEM_H
