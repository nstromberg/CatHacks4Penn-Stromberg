#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#ifndef HEADERS
#define HEADERS
#include "time.h"
#include "sec.h"
#endif
enum rateNames
{
  daysInClass,compactness,lateStart,earlyFinish
};
class Sol
{
  private:
    int rating;
    std::list<Time> solTimes;
    std::vector<Sec> solSecs;
  public:
    Sol();
    bool isOverlapping();
    int evaluate();
    int getRating();
    std::vector<Sec> getSecs();
    void addSec(Sec& newSec);
    void print();

};