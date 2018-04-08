#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
struct STime4
{
  char day;
  int start;
  int end;
  static bool cmp(const STime& a, const STime& b)
  {
    return a.start<b.start;
  }
  bool sover(STime4 next)
  {
    return(end>next.start);
  }
  bool over(const STime4 other)
  {
    return(start<other.end && other.start<end);
  }
};
