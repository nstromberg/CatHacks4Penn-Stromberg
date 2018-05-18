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
    explicit CourseWidget(QWidget *parent = 0);
//    explicit CourseWidget(std::string courseName, bool courseRequired, QWidget *parent=0);
    ~CourseWidget();
    bool getRequired();
    bool getName();
    void setRequired();
    void setParams(std::string name, bool required);
    Course courseObj;
private:
    Ui::CourseWidget *ui;

};

#endif // COURSEWIDGET_H
