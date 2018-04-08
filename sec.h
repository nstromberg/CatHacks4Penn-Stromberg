#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#ifndef SEC_H
#define SEC_H
#include "stime.h"
#endif
class Sec
{
  private:
    std::list<STime> times;
    std::string course;
    int number;
  public:
    Sec();
    void readSec(std::ifstream& in);
    void setTimes(std::list<STime>& newTimes);
    std::list<STime> getTimes();
    void setNumber(int num);
    int getNumber();
    void setCourse(std::string courseName);
    std::string getCourse();
    void print();

};
