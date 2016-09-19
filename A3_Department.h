#ifndef A3_DEPARTMENT_H
#define A3_DEPARTMENT_H

#include <string>
using namespace std;

class department//Creating class department.
{
  friend class University;//Make university a friend of this class to have access to this class's functions.
 private://The following attributes are private.
  long id;
  string name;
  string location;
  long chairId;
  static long nextDepartId;//Important to make this static. We will be incrementing this everytime a department object is made.
 public:
  department(string,string,long);//department constructor accepting 3 parameters.
  void print()const;//Print function that prints the required attributes.
};

#endif
