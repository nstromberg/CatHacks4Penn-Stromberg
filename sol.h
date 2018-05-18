#ifndef SOL_H
#define SOL_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include "sec.h"

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
    static int slider;
    static int weights[4];
    static double meanStartEx[2];
    static double meanEndEx[2];
    static double numDaysEx[2];
    static double compactEx[2];
  public:
    Sol();
    bool isOverlapping();
    void makeRaw();
    void makeScaled();
    void makeTotal();
    int getRating();
    std::vector<Sec> getSecs();
    static void setWeights(int newWeights[]);
    static void setSlider(int newSlider);
    void addSec(Sec& newSec);
    void print();

};

#endif
