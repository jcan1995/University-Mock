#include "A3_Faculty.h"//Important to include the header file. We don't need to include supper class file since it's already included in "A3_Faculty.h".
#include <iostream>
#include <string>
using namespace std;

long faculty::nextFacultyId = 600;//Set static variable nextFacultyId equal to 600.

faculty::faculty(string n,string em,string ad,string DO,string gend,float sal,int YOE,long depart):person(id,n,em,ad,DO,gend)//This constructor accepts 8 parameters although 6 of these get passed to the super person class to get initialized.
{
  id = nextFacultyId;//Set id equal to nextFacultyId.
  salary = sal;
  yearOfExp = YOE;
  departId = depart;
  nextFacultyId++;//Increment nextFacultyId to get a different id everytime an object of faculty is made.
}

void faculty::print()const//A print function that only prints the required attributes for this assignment.
{
  cout<<"ID: "<<id<<endl;
  cout<<"Name: "<<name<<endl;
}
