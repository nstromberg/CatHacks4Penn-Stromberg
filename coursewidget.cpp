#include "coursewidget.h"
#include "ui_coursewidget.h"
#include "course.h"

CourseWidget::CourseWidget(std::string courseName, bool courseRequired, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CourseWidget)
{
    ui->setupUi(this);
    courseObj.name = courseName;
    courseObj.req = req;
}

CourseWidget::~CourseWidget()
{
    delete ui;
}

bool CourseWidget::getRequired()
{
    return ui->checkBox->tristate();
}
