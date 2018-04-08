#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#ifndef HEADERS
#define HEADERS
#include "time.h"
#include "sec.h"
#endif
class Course
{
  public:
    Course(std::string newName, bool required);
    std::vector<Sec> sections;
    bool req;
    std::string name;
};
