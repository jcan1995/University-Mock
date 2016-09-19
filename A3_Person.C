#include "A3_Person.h"//Include the header file here.
#include <iostream>
#include <string>
using namespace std;

person::person(long FacId,string n,string mail,string home,string DOB,string sex)//Constructor that accepts 6 parameters that will be passed from child classes.
{
  id = FacId;
  name = n;
  email = mail;
  address = home;
  dateOfBirth = DOB;
  gender = sex;
}

void person::print() const//Print function just in case ;)
{
  cout<<"ID: "<<id<<endl;
  cout<<"name: "<<name<<endl;
  cout<<"Email: "<<email<<endl;
  cout<<"Address: "<<address<<endl;
  cout<<"Date Of Birth: "<<dateOfBirth<<endl;
  cout<<"Gender: "<<gender<<endl;
}
