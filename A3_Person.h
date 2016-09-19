#ifndef A3_PERSON_H
#define A3_PERSON_H

#include <string>
using namespace std;

class person//Super class! Both Faculty and student share these attributes.
{
  friend class University;//Make friends so we have access to this class's functions.
 protected://Protected since two classes will be utilizing these attributes.
  long id;
  string name;
  string email;
  string address;
  string dateOfBirth;
  string gender;

 public:
  person(long,string,string,string,string,string);//Constructor which accepts 6 parameters.
  void print() const;//Print function.
};


#endif

