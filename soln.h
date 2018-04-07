#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#ifndef HEADERS
#define HEADERS
#include "time.h"
#include "sec.h"
#endif
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
    void print();

};
