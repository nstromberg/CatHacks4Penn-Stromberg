#include <iostream>
#include <algorithm>
#include "sec.h"
#include "time.h"
#include <vector>
#include <list>

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

}
