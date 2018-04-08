#ifndef COURSEWIDGET_H
#define COURSEWIDGET_H

#include <QWidget>
#include "course.h"

namespace Ui {
class CourseWidget;
}

class CourseWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CourseWidget(std::string courseName, bool courseRequired, QWidget *parent = 0);
    ~CourseWidget();
    bool getRequired();
    bool getName();

private:
    Ui::CourseWidget *ui;
    Course courseObj;
};

#endif // COURSEWIDGET_H
