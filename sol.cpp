#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include "sol.h"
//raw ratings are unscaled numbers that rate solutions by a quality
//scaled ratings are doubles from 0 to 1 that represent how the raw ratings stand 
Sol::Sol()
{
  rating=0;
}

int Sol::slider = 0;
int Sol::weights[] ={0,0,0,0};
//extrema of each raw rating
double Sol::meanStartEx[] = {0,0};
double Sol::meanEndEx[]={0,0};
double Sol::numDaysEx[]={0,0};
double Sol::compactEx[]={0,0};

bool Sol::isOverlapping()
{
  for(auto i=solTimes.begin();i!=solTimes.end();i++)
  {
    for(auto j=(i->second).begin();j!=(i->second).end()-1;j++)
    {  
      if( (*j).sover(*(j++)) )
        return true;
    }
  }
  return false;
}

void Sol::makeRaw()
{
  //count days that have times
  rawRatings[daysInClass]=(double)(solTimes.size());
  //count space in between class times
  rawRatings[compactness]=0;
  for(auto i=solTimes.begin();i!=solTimes.end();i++)
  {
    //Not sure if iterator -1, +1 works
    for(auto j=(i->second).start();j!=(i->second).end()-1;i++)
    {
      rawRatings[compactness]+=((j+1)->start)-(j->end);
    }
  }
  //average start time
  double num=0;
  double den=0;
  for(auto i = solTimes.begin();i!=solTimes.end();i++)
  {
    auto j=(i->second).begin();
    num+=j->start;
    den++;
  }
  rawRatings[lateStart]=num/den;
  //average finish time
  num=0;
  den=0;
  for(auto i = solTimes.begin();i!=solTimes.end();i++)
  {
    auto j=(i->second).rbegin();
    num+=j->end;
    den++;
  }
  rawRatings[earlyFinish]=num/den;
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
  for(int i=0;i<4;i++)
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
void Sol::setWeights(int newWeights[])
{
  for(int i=0;i<4;i++)
  {
    weights[i]=newWeights[i];
  }
}
void Sol::setSlider(int newSlider)
{
  slider=newSlider;
}
void Sol::addSec(Sec& newSec)
{
  solSecs.push_back(newSec);
  std::list<STime> temp=newSec.getTimes();
  for(auto j=temp.begin();j!=temp.end();)
  {
    if(solTimes.find(j->day)==solTimes.end())
    {
      solTimes[j->day]=*j;
    }
    else
    {
      for(auto i =solTimes[j->day].begin();i!=solTimes[j->day].end();i++)
      {
        if(STime::cmp(*j, *i))
        {
          solTimes[j->day].insert(i,*j);
          j++;
        }
      }
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

