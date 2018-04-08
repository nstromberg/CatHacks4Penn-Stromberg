#include <string>
#include "course.h"
Course::Course()
{
  name="";
  req=false;
}
Course::Course(std::string newName,bool required)
{
  name=newName;
  req=required;
}
