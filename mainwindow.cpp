#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "creditwidgetitem.h"
#include "avoidwidgetitem.h"
#include "requirewidgetitem.h"
#include "classwidgetitem.h"
#include "lunchwidgetitem.h"
#include "coursewidget.h"
#include "course.h"
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <typeinfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addPrefButton_clicked()
{
    QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget);
    ui->listWidget->addItem(listWidgetItem);
    QString selection = ui->comboBox->currentText();

    if(selection.contains("Credit"))
    {
        CreditWidgetItem *creditWidgetItem = new CreditWidgetItem;
        listWidgetItem->setSizeHint(creditWidgetItem->sizeHint());
        ui->listWidget->setItemWidget(listWidgetItem,creditWidgetItem);
    }
    else if(selection.contains("Class"))
    {
        ClassWidgetItem *classWidgetItem = new ClassWidgetItem;
        listWidgetItem->setSizeHint(classWidgetItem->sizeHint());
        ui->listWidget->setItemWidget(listWidgetItem,classWidgetItem);
    }
    else if(selection.contains("Lunch"))
    {
        LunchWidgetItem *lunchWidgetItem = new LunchWidgetItem;
        listWidgetItem->setSizeHint(lunchWidgetItem->sizeHint());
        ui->listWidget->setItemWidget(listWidgetItem,lunchWidgetItem);
    }
    else if(selection.contains("Avoid"))
    {
        AvoidWidgetItem *avoidWidgetItem = new AvoidWidgetItem;
        listWidgetItem->setSizeHint(avoidWidgetItem->sizeHint());
        ui->listWidget->setItemWidget(listWidgetItem,avoidWidgetItem);
    }
    else if(selection.contains("Require"))
    {
        RequireWidgetItem *requireWidgetItem = new RequireWidgetItem;
        listWidgetItem->setSizeHint(requireWidgetItem->sizeHint());
        ui->listWidget->setItemWidget(listWidgetItem,requireWidgetItem);
    }

}

std::map<std::string, std::vector<std::vector<int>>> MainWindow::getItems()
{
    std::map<std::string,std::vector<std::vector<int>>> reqs;
    std::vector<std::vector<int>> vectorVector;
    std::vector<int> intVector;
    std::vector<int> fieldIndex;
    QLineEdit *lineEdit = new QLineEdit;
    QWidget *widget = new QWidget;

    for(int i = 0; i<ui->listWidget->count(); i++)
    {
        widget = qobject_cast<QWidget *>(ui->listWidget->itemWidget(ui->listWidget->item(i)));
        for(int k = 0; k<widget->children().count(); k++)
            if(typeid(widget->childAt(i,0))==typeid(QLineEdit))
                fieldIndex.push_back(k);
        for(int j = 0; j<fieldIndex.size(); j++)
        {
            lineEdit = qobject_cast<QLineEdit *>(widget->childAt(fieldIndex.at(j),0));
            intVector.push_back(lineEdit->text().toInt());
        }
        reqs[widget->objectName().toStdString()].push_back(intVector);
    }
    return reqs;
}


void MainWindow::on_calcButton_clicked()
{
    //FOR TESTING ONLY
    std::map<std::string, std::vector<std::vector<int>>> info = getItems();
    for(auto i = info.begin(); i!=info.end(); i++)
    {
        std::string tmp = i->first;
        ui->plainTextEdit->appendPlainText(QString::fromStdString(tmp));
        ui->plainTextEdit->appendPlainText(QString::number(i->second.size()));
    }
    //END TESTING

    CourseWidget *widget = new CourseWidget;
    std::vector<Course> courses;
    for(int i = 0; i<ui->classList->count(); i++)
    {
        widget = qobject_cast<QWidget *>(ui->classList->itemWidget(ui->classList->item(i)));
        courses.push_back(widget->courseObj);
    }
}

void MainWindow::on_searchBox_returnPressed()
{
    //SEARCH
    std::string search = ui->searchBox->text().toStdString();
    std::ifstream fin;
    fin.open("C:\\Users\\natha\\Documents\\CatHacks4GUI\\output.txt");
    if(fin.fail())
    {
        ui->plainTextEdit->appendPlainText("Error: Could not read database file");
    }

    std::string line;
    std::size_t pos;
    QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->classList);
    ui->classList->addItem(listWidgetItem);

    while(fin.good())
    {
        getline(fin,line);
        pos = line.find(search);
        if(pos!=std::string::npos)
        {
            CourseWidget *course = new CourseWidget(search, false);
            listWidgetItem->setSizeHint(course->sizeHint());
            ui->classList->setItemWidget(listWidgetItem,course);
            break;
        }
    }
    //ADD TO LIST

}
