#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#ifndef COURSE_H
#define COURSE_H
#include "sec.h"
class Course
{
  public:
    Course();
    Course(std::string newName, bool required);
    std::vector<Sec> sections;
    bool req;
    std::string name;
};

#endif
