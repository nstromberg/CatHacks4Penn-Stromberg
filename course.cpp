#include <string>
#include "course.h"
Course::Course(std::string newName,bool required)
{
  name=newName;
  req=required;
}
