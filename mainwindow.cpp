#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "creditwidgetitem.h"
#include "avoidwidgetitem.h"
#include "requirewidgetitem.h"
#include "classwidgetitem.h"
#include "lunchwidgetitem.h"
#include "course.h"
#include "sol.h"
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

std::map<std::string, std::vector<std::vector<std::string>>> MainWindow::getItems()
{
    std::map<std::string,std::vector<std::vector<std::string>>> reqs;
    std::vector<std::string> stringVector;
    QLineEdit *lineEdit = new QLineEdit;
    QWidget *widget = new QWidget;

    for(int i = 0; i<ui->listWidget->count(); i++)
    {
        widget = qobject_cast<QWidget *>(ui->listWidget->itemWidget(ui->listWidget->item(i)));
        foreach(QLineEdit *edit, widget->findChildren<QLineEdit *>())
        {
            stringVector.push_back(edit->text().toStdString());
        }
        reqs[widget->objectName().toStdString()].push_back(stringVector);
        stringVector.clear();
    }
    return reqs;
}


void MainWindow::on_calcButton_clicked()
{
    int classStart, classEnd, lunchLength, lunchTime,avoidSection, requireSection, numAvoidWidget, numRequireWidget, compactSliderValue, weights[4];
    std::string avoidClass, requireClass;

    std::map<std::string, std::vector<std::vector<std::string>>> info = getItems();
    for(auto i = info.begin(); i!=info.end(); i++)
    {
        std::string tmp = i->first;
        std::vector<std::vector<std::string>> second = i->second;

        if(tmp.compare("ClassWidgetItem")==0)
        {
            try
            {
                classStart = std::stoi(second[0][0]);
                classEnd = std::stoi(second[0][1]);
                ui->plainTextEdit->appendPlainText(QString::fromStdString("CLASS VALUES: ")+QString::number(classStart) + QString::number(classEnd));

            }catch (...)
            {
                ui->plainTextEdit->appendPlainText("CLASS VALUES: Invalid");
            };
        }else if(tmp.compare("CreditWidgetItem")==0)
        {
            try
            {

                ui->plainTextEdit->appendPlainText(QString::fromStdString("CREDIT VALUES: ")+QString::number(std::stoi(second[0][0])) + QString::number(std::stoi(second[0][1])));
            }catch (...)
            {
                ui->plainTextEdit->appendPlainText("CREDIT VALUES: Invalid");
            };
        }else if(tmp.compare("LunchWidgetItem")==0)
        {
            try
            {
                ui->plainTextEdit->appendPlainText(QString::fromStdString("LUNCH VALUES: ")+QString::number(std::stoi(second[0][0])) + QString::number(std::stoi(second[0][1])));
            }catch (...)
            {
                ui->plainTextEdit->appendPlainText("LUNCH VALUES: Invalid");
            };
        }else if(tmp.compare("AvoidWidgetItem")==0)
        {
            for(int i = 0; i<second.size(); i++)
            {
                try
                {
                    ui->plainTextEdit->appendPlainText(QString::fromStdString("AVOID VALUES: ")+QString::number(std::stoi(second[i][0])) + QString::fromStdString(second[i][1]));
                }catch (...)
                {
                    ui->plainTextEdit->appendPlainText("AVOID VALUES: Invalid");
                };
            }

        }else if(tmp.compare("RequireWidgetItem")==0)
        {
            for(int i = 0; i<second.size(); i++)
            {
                try
                {
                    ui->plainTextEdit->appendPlainText(QString::fromStdString("REQUIRE VALUES: ")+QString::number(std::stoi(second[i][0])) + QString::fromStdString(second[i][1]));
                }catch (...)
                {
                    ui->plainTextEdit->appendPlainText("REQUIRE VALUES: Invalid");
                };
            }
        }
    }

    compactSliderValue = ui->compactSlider->value();
    weights[0] = ui->daysWeight->value();
    weights[1] = ui->compactWeight->value();
    weights[2] = ui->startWeight->value();
    weights[3] = ui->endWeight->value();

    for(int row = 0; row < ui->classList->count(); row++)
    {
             QListWidgetItem *item = ui->classList->item(row);

    }

    Sol::setSlider(compactSliderValue);
    Sol::setWeights(weights);

    CourseWidget *widget = new CourseWidget();
    std::vector<Course> courses;
    for(int i = 0; i<ui->classList->count(); i++)
    {
        widget = qobject_cast<CourseWidget *>(ui->classList->itemWidget(ui->classList->item(i)));
        courses.push_back(widget->courseObj);
    }
}

void MainWindow::on_searchBox_returnPressed()
{
    //SEARCH
    std::string search = ui->searchBox->text().toStdString();
    std::ifstream fin;
    fin.open("C:\\Users\\natha\\Documents\\GitHub\\CatHacks4Penn-Stromberg\\output.txt");
    if(fin.fail())
    {
        ui->plainTextEdit->appendPlainText("Error: Could not read database file");
    }

    std::string line;
    std::size_t pos;


    Course newCourse;
    while(fin.good())
    {
        getline(fin,line);
        pos = line.find(search);
        if(pos!=std::string::npos)
        {
            QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->classList);
            ui->classList->addItem(listWidgetItem);
            CourseWidget *course = new CourseWidget();
            course->setParams(search, false);
            listWidgetItem->setSizeHint(course->sizeHint());
            ui->classList->setItemWidget(listWidgetItem,course);
            Sec tempSec;
            Course tempCourse;
            int numSec=0;
            std::list<Sec> secList;
            fin.ignore(search.length());
            fin >> numSec;
            fin.ignore(256,'\n');
            for(int i = 0; i<numSec;i++)
            {
                tempSec.readSec(fin);
                secList.push_back(tempSec);
            }
            tempCourse.name = search;
            tempCourse.sections = secList;
            coursePool.insert(tempCourse);
            break;
        }
    }
    if(pos==std::string::npos){
        ui->plainTextEdit->appendPlainText("Class " + QString::fromStdString(search)+" not in database");
    }
    //ADD TO LIST

}

void MainWindow::on_remPrefButton_clicked()
{

}
