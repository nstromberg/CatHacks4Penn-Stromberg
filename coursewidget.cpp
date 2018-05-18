#include "coursewidget.h"
#include "ui_coursewidget.h"


//CourseWidget::CourseWidget(std::string courseName, bool courseRequired, QWidget *parent) :
//    QWidget(parent),
//    ui(new Ui::CourseWidget)
//{
//    ui->setupUi(this);
//    courseObj.name = courseName;
//    courseObj.req = courseRequired;
//}
CourseWidget::CourseWidget( QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CourseWidget)
{
    ui->setupUi(this);
}

CourseWidget::~CourseWidget()
{
    delete ui;
}

bool CourseWidget::getRequired()
{
    return ui->checkBox->isChecked();
}

void CourseWidget::setRequired()
{
    courseObj.req = getRequired();
}

void CourseWidget::setParams(std::string name, bool required){
    courseObj.name = name;
    courseObj.req = required;
    ui->courseName->setText(QString::fromStdString(name));
}
