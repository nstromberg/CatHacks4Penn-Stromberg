#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "time.h"
class Sec
{
  private:
    std::list<Time> times;
    std::string course;
    int number;
  public:
    void setTimes(std::list<Time>);
    std::list<Time> getTimes();
    void setNumber(int num);
    int getNumber();
    void setCourse(std::string course);
    std::string getCourse();
    void print();
}
