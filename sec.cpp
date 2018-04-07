#include <fstream>
#include <string>
#include <list>
#ifndef HEADERS
#define HEADERS
#include "time.h"
#include "sec.h"
#endif
void Sec::readSec(std::ifstream& in)
{
  char trash='\0';
  int numTimes=0;
  in>>numTimes;
  numTimes--;
  int secNum=0;
  in>>secNum;
  this->setNumber(secNum);
  for(int i=0;i<numTimes;i++)
  {
    std::string days="";
    char aorp1='\0';
    char aorp2='\0';
    int hour1=0;
    int minute1=0;
    int hour2=0;
    int minute2=0;
    in>>days>>hour1>>trash>>minute1>>aorp1;
    in.ignore(3,'-');
    in>>days>>hour2>>trash>>minute2>>aorp2;
    if(hour1==12)
    {
      hour1-=12;
    }
    if(aorp1=='p')
    {
      hour1+=12;
    }
    if(hour2==12)
      hour2-=12;
    if(aorp2=='p')
      hour2+=12;
    Time t;
    t.start=(hour1+minute1/60)*100;
    t.end=(hour2+minute2/60)*100;
    for(int j=0;j<days.length();j++)
    {
      t.day=days[i];
      this->times.push_back(t);
    }
  }

}
