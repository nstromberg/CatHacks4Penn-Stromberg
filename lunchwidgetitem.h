#ifndef LUNCHWIDGETITEM_H
#define LUNCHWIDGETITEM_H

#include <QWidget>

namespace Ui {
class LunchWidgetItem;
}

class LunchWidgetItem : public QWidget
{
    Q_OBJECT

public:
    explicit LunchWidgetItem(QWidget *parent = 0);
    ~LunchWidgetItem();

private:
    Ui::LunchWidgetItem *ui;
};

#endif // LUNCHWIDGETITEM_H
