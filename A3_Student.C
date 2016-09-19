#include "A3_Student.h"//Include header file.
#include <vector>
#include <iostream>
#include <string>
using namespace std;

long student::nextStId = 500;//Initialize static attribute to 500.

student::student(string nm,string m,string add,string DB,string gen,int yr,string maj,long adv):person(nextStId,nm,m,add,DB,gen)//This class accepts 8 parameters and passes 6 to parent class to be initialized.
{
  yearOfStudy = yr;
  major = maj;
  advisorId = adv;
  nextStId++;//Increment nextStId and pass to parent class.
}

void student::print() const//Print function that prints only the required attribues for this assignment.
{
  cout<<"ID: "<<id<<endl;
  cout<<"Name: "<<name<<endl;
}
