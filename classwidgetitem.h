#ifndef CLASSWIDGETITEM_H
#define CLASSWIDGETITEM_H

#include <QWidget>

namespace Ui {
class ClassWidgetItem;
}

class ClassWidgetItem : public QWidget
{
    Q_OBJECT

public:
    explicit ClassWidgetItem(QWidget *parent = 0);
    ~ClassWidgetItem();

private:
    Ui::ClassWidgetItem *ui;
};

#endif // CLASSWIDGETITEM_H
