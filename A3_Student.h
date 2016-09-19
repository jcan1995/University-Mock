#ifndef A3_STUDENT_H
#define A3_STUDENT_H

#include "A3_Course.h"//Include this header file since we have a vector of type course.
#include "A3_Person.h"//Include this since student is a child class of person
#include<string>
#include<vector>//For a vector we are going to make.
using namespace std;

class student: public person//Here is where we state that we will be using attributes from parent class.
{
  friend class University;//Make friends so University can utilize functions from this class.
 private://Following attributes are not from parent class. Thus they're private.
  int yearOfStudy;
  string major;
  long advisorId;
  vector <course> coursesTaken;//A vector of courses of type course.
  static long nextStId;
 public:
  student(string,string,string,string,string,int,string,long);//A constructor accepting 8 parameters.
  void print()const;//Print function.
};
#endif
