#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include "sol.h"
Sol::Sol()
{
  rating=0;
}
int Sol::numDaysEx[2]={0,0};
double Sol::compactEx[2]={0,0};
double Sol::meanEndEx[2]={0,0};
double Sol::meanStartEx[2]={0,0};
bool Sol::isOverlapping()
{
  for(auto i=solTimes.begin();i!=solTimes.end();i++)
  {  
    if( (*i).sover(*(i++)) )
      return true;
  }
  return false;
}

void Sol::makeRaw()
{
  std::set<char> days;
  for(auto i=solTimes.begin();i!=solTimes.end();i++)
  {
    days.insert((*i).day);
  }
  
  int temp=days.size();
  if(temp>Sol::numDaysEx[1])
    Sol::numDaysEx[1]=temp;
  else if(temp<Sol::numDaysEx[0])
    Sol::numDaysEx[0]=temp;
  
  
  rawRatings[daysInClass]=(double)(temp);
  /*
  rawRatings[compactness]=;
  rawRatings[lateStart]=;
  rawRatings[earlyFinish]=;
  */
}

void Sol::makeScaled()
{
  //Once all solutions have been found
  scaledRatings[daysInClass]=(rawRatings[daysInClass]-numDaysEx[0])/(numDaysEx[1]-numDaysEx[0]);
  scaledRatings[compactness]=(rawRatings[compactness]-compactEx[0])/(compactEx[1]-compactEx[0]);
  scaledRatings[lateStart]=(rawRatings[lateStart]-meanStartEx[0])/(meanStartEx[1]-meanStartEx[0]);
  scaledRatings[earlyFinish]=(meanEndEx[1]-rawRatings[earlyFinish])/(meanEndEx[1]-meanEndEx[0]);
}

void Sol::makeTotal()
{
  //Once all solutions have been found
}

int Sol::getRating()
{
  return rating;
}
std::vector<Sec> Sol::getSecs()
{
  return solSecs;
}
void Sol::addSec(Sec& newSec)
{
  solSecs.push_back(newSec);
  auto j=newSec.getTimes().begin();
  for(auto i =solTimes.begin();i!=solTimes.end();i++)
  {
    if(STime::cmp(*j, *i))
    {
      solTimes.insert(i,*j);
      j++;
    }
  }
}
void Sol::print()
{
  for(int i=0; i<solSecs.size();i++)
  {
    solSecs[i].print();
  }
}

