#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#ifndef HEADERS
#define HEADERS
#include "stime.h"
#include "sec.h"
#include "sol.h"
#endif
Sol::Sol()
{
  rating=0;
}
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
  
  /*
  rawRatings[Sol::daysInClass]=(double)(temp);
  rawRatings[Sol::compactness]=;
  rawRatings[Sol::lateStart]=;
  rawRatings[Sol::earlyFinish]=;
  */
}

void Sol::makeScaled()
{
  //Once all solutions have been found
  scaledRatings[Sol::daysInClass]=
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

