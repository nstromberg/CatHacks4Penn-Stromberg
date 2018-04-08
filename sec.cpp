#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iomanip>
#ifndef HEADERS
#define HEADERS
#include "stime.h"
#include "sec.h"
#endif
Sec::Sec()
{
  course="";
  number=0;
}
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
    STime t;
    t.start=(hour1*60+minute1);
    t.end=(hour2*60+minute2);
    for(int j=0;j<days.length();j++)
    {
      t.day=days[i];
      this->times.push_back(t);
    }
    this->times.sort(STime::cmp);
  }

}
void Sec::setTimes(std::list<STime>& newTimes)
{

  times=newSTimes;
}
std::list<STime> Sec::getTimes()
{
  return times;
}
void Sec::setNumber(int num)
{
  number=num;
}
int Sec::getNumber()
{
  return number;
}
void Sec::setCourse(std::string courseName)
{
  this->course=course;
}
std::string Sec::getCourse()
{
  return course;
}
void Sec::print()
{
  std::cout<<course<<"-"<<std::setw(3)<<std::setfill('0')<<number<<'\n';
}
