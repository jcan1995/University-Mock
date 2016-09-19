#include"A3_Department.h"//Important to include the classes header file.
#include <iostream>
#include <string>
using namespace std;

long department::nextDepartId = 100;//Initialize static member "nextDepartId" to 100.

department::department(string n,string loc,long chair)//Constructor that accepts 3 parameters.
{
  id = nextDepartId;//Important to set id equal to the static member nextDepartId to get a different id everytime one is created.
  name = n;
  location = loc;
  chairId = chair;
  nextDepartId++;//Increment the static member nextDepartId.
}

void department::print()const//A print function that only prints the required attributes for this assignment.
{
  cout<<"Name: "<<name<<endl;
  cout<<"Location: "<<location<<endl;
  cout<<"Chair Id: "<<chairId<<endl;
}
