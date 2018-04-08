#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#ifndef HEADERS
#define HEADERS
#include "time.h"
#include "sec.h"
#include "sol.h"
#endif
Sol::Sol()
{
  rating=0;
}
bool Sol::isOverlapping()
{

}
int Sol::evaluate()
{

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
    if(Time::cmp(*j, *i))
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

