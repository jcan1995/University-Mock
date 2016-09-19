#ifndef A3_COURSE_H
#define A3_COURSE_H

#include <string>
using namespace std;

class course//Create class course with 7 attributes.
{
  friend class University;//Make University a friend to have access to the functions from this class.
 private://Following attributes are private.
  long CRN;
  int maxAvailableSeats;
  string name;
  long departId;
  long assignedSeats;
  long isTaughtBy;
  static long nextCRN;//Static because it will be incremented every time an object is made.
 public://Following functions are public.
  course();//Constructor
  course(int,string,long,long);//Constructor that takes four parameters to initialize some of these attributes.
  void print()const;//A print function.
};

#endif
