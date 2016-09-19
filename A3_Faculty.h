#ifndef A3_FACULTY_H
#define A3_FACULTY_H

#include "A3_Person.h"//We have a supper class called "person". We will be utilizing its attributes here.
#include <string>
using namespace std;

class faculty:protected person//Make the attributes we are using here from the supper class "person" protected.
{
  friend class University;//Make University a friend of this class so that we have access to this classes functions.
 private:
  float salary;
  int yearOfExp;
  long departId;
  static long nextFacultyId;
 public:
  faculty(string,string,string,string,string,float,int,long);//Constructor that accepts 8 parameters. Five of which that will be passed to the supper class "person".
  void print() const;//Constant print function.
};

#endif
