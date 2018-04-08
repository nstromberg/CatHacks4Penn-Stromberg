#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
struct Time
{
  char day;
  int start;
  int end;
  static bool cmp(const Time& a, const Time& b)
  {
    return a.start<b.start;
  }
  bool sover(Time next)
  {
    return(end>next.start);
  }
  bool over(const Time other)
  {
    return(start<other.end && other.start<end);
  }
};
