#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#ifndef HEADERS
#define HEADERS
#include "stime.h"
#include "sec.h"
#endif
enum rateNames
{
  daysInClass,compactness,lateStart,earlyFinish
};
class Sol
{
  private:
    double rating;
    std::vector<double> scaledRatings;
    std::vector<double> rawRatings;
    std::list<STime> solTimes;
    std::vector<Sec> solSecs;
    static double meanStartEx[2];
    static double meanEndEx[2];
    static int numDaysEx[2];
    static double compactEx[2];
  public:
    Sol();
    bool isOverlapping();
    void makeRaw();
    void makeScaled();
    void makeTotal();
    int getRating();
    std::vector<Sec> getSecs();
    void addSec(Sec& newSec);
    void print();

};
