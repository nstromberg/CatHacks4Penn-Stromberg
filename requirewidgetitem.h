#ifndef REQUIREWIDGETITEM_H
#define REQUIREWIDGETITEM_H

#include <QWidget>

namespace Ui {
class RequireWidgetItem;
}

class RequireWidgetItem : public QWidget
{
    Q_OBJECT

public:
    explicit RequireWidgetItem(QWidget *parent = 0);
    ~RequireWidgetItem();

private:
    Ui::RequireWidgetItem *ui;
};

#endif // REQUIREWIDGETITEM_H
