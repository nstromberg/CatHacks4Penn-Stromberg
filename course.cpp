#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#ifndef HEADERS
#define HEADERS
#include "time.h"
#include "sec.h"
#include "course.h"
#endif
Course::Course(std::string newName,bool required)
{
  name=newName;
  req=required;
}
