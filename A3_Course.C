#include <iostream>
#include <string>
#include "A3_Course.h"//Important to include the header file.
using namespace std;

long course::nextCRN = 200;//Initialize static member "nextCRN" to 200.

course::course(){//default constructor.
  assignedSeats = 0;
  assignedSeats++;
}
course::course(int maxAvailable,string n, long depId,long TaughtBy)//Constructor that takes the following parameters.
{
  CRN = nextCRN;//Important to set CRN to nextCRN so each course gets a different ID number.
  maxAvailableSeats = maxAvailable;
  name = n;
  departId = depId;
  isTaughtBy = TaughtBy;//Best to have different names. For some reason wasn't getting the right output by using "isTaughtBy = isTaughtBy"
  assignedSeats = 0;
  nextCRN++;//Increment nextCRN.

}

void course::print()const//Print function used to print only the required outputs for this assignment..
{
  cout<<"CRN: "<<CRN<<endl;
  cout<<"Name: "<<name<<endl;
}
