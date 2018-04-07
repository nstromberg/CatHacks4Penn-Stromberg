#include <iostream>
#include <string>
#include <vector>
#include <list>
#ifndef HEADERS
#define HEADERS
#include "time.h"
#include <fstream>
#endif
class Sec
{
  private:
    std::list<Time> times;
    std::string course;
    int number;
  public:
    Sec();
    void readSec(std::ifstream& in);
    void setTimes(std::list<Time>);
    std::list<Time> getTimes();
    void setNumber(int num);
    int getNumber();
    void setCourse(std::string course);
    std::string getCourse();
    void print();

};
