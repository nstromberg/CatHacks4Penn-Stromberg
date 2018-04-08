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
int Sol::weights[4]={0,0,0,0};
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
  if(temp>numDaysEx[1])
    numDaysEx[1]=temp;
  else if(temp<numDaysEx[0])
    numDaysEx[0]=temp;
  
  
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
  double x=((double)(slider))/100.0;
  scaledRatings[compactness]=(1-std::abs(x-scaledRatings[compactness]))/std::max(x,1-x);
  scaledRatings[lateStart]=(rawRatings[lateStart]-meanStartEx[0])/(meanStartEx[1]-meanStartEx[0]);
  scaledRatings[earlyFinish]=(meanEndEx[1]-rawRatings[earlyFinish])/(meanEndEx[1]-meanEndEx[0]);
}

void Sol::makeTotal()
{
  //Once all solutions have been found
  rating=0;
  for(int i=0;i<weights.size();i++)
  {
    rating+=((double)(weights[i]))*scaledRatings[i];
  }
}

int Sol::getRating()
{
  return rating;
}
std::vector<Sec> Sol::getSecs()
{
  return solSecs;
}
static void Sol::setWeights(int[] newWeights)
{
  for(int i=0;i<4;i++)
  {
    weights[i]=newWeights[i];
  }
}
static void Sol::setSlider(int newSlider)
{
  slider=newSlider;
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

