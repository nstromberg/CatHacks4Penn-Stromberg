#include <fstream>
#include <string>
#include <list>
#include "time.h"
ifstream& operator >> (&ifstream in, Sec out)
{
  char trash;
  int numTimes;
  in>>numTimes;
  numTimes--;
  int secNum;
  in>>secNum;
  out.setNumber(secNum);
  std::list<Time> times;
  for(int i=0;i<numTimes;i++)
  {
    std::string days;
    cin>>days;
  }
}
