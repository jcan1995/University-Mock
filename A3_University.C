#include<vector>
#include<fstream>
#include<string>
#include<iostream>
#include"A3_University.h"//Include header file.
using namespace std;

bool University::failure = false;//Set failure equal to false.
bool University::success = true;//Set success equal to true. Makes code more understandable and easier to read.

bool University:: checkDepChairId(long depChairId){//
  for(int i = 0; i < Faculties.size();i++){//Go through each element in the Faculties vector.
    if(Faculties[i].id == depChairId)//If the id # in the Faculties element number i equals depChairId return succes.
      return success;
  }
   return failure;//Otherwise return failure. The depChair id could not be found.
}

bool University:: CreateNewDepartment(string depName, string depLoc, long depChairId)//This method accepts three parameters which are needed to create an object of type department. These include a department name,department location, and a department chair id.
{
   
  if((depChairId != 0)&& !checkDepChairId(depChairId)){//If the department chair ID does not equal zero, the department chair is known so return failure.
       return failure;
  }
     
  department D(depName,depLoc,depChairId);//Make a 'D' object of type department.
  Departments.push_back(D);;//Push object 'D' into the element after the last element in the Departments vector.
  return success;//Return success.
}

bool University:: ListDepartments(){//This function will print out all of the departments that we were able to create.
  cout<<"-------List of departments--------"<<endl;
  for(int i = 0; i < Departments.size(); i++){
    cout<<"Department ID: "<< Departments[i].id<<endl;
    cout<<"Department Name: "<< Departments[i].name<<endl;
  }
  cout<<"----------------------------------"<<endl;
  return success;//Return succecss.
}
//---------------------------------------------------------------------------------------------------------------
bool University::CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth,string fGender,float fSalary, int fYearOfExp, long fDepId)//This function will create a new faculty memeber under a few conditions.
{
  if(!checkDepId(fDepId))//If the department number of the faculty doesn't match up with any department number then print this message and return failure.
    {
      cout<<"Not a valid department ID!"<<endl;
      return failure;//Return failure.
    }
  
  faculty f(fName,fEmail,fAddress,fDateOfBirth,fGender,fSalary,fYearOfExp,fDepId);//Make a object f of type faculty which accepts these parameters.
  Faculties.push_back(f);//Push the object to the back of the vector.
  return success;//Return success.
}

bool University::checkDepId(long depId){//Thisd function is a condition check for "CreateNewFaculty" function.
  for(int i = 0; i < Departments.size(); i++)
    {
      if (Departments[i].id == depId)//If a department id from a vector matches with the id passed in the parameters then return success. 
	{
	  return success;
	}
    }
  return failure;//Else return failure.
}

//---------------------------------------------------------------------------------------------------------------

bool University:: ListFaculties(){//This function lists all the current faculties.
  cout<<"-------List of faculties--------"<<endl;
  for(int i = 0; i <Faculties.size();i++){//Prints out the ids and names of each faculty member.
    cout<<"Faculty ID: "<<Faculties[i].id<<endl;
    cout<<"Faculty name: "<<Faculties[i].name<<endl;
  }
  cout<<"--------------------------------"<<endl;
}

bool University::ListFacultiesInDepartment(long departId)
{
  if(!checkDepId(departId))
    return failure;
  cout<<"------Faculties in department#:"<<departId<<"-------"<<endl;
  for(int i = 0; i < Faculties.size();i++){//Prints out the IDs and names of each faculty member according to their department numbers.
    if(Faculties[i].departId == departId)//If the department number from "faculties" class match the department number passed,continue.
      Faculties[i].print();//Use the print function from class "faculty".
  }
  cout<<"-----------------------------------------"<<endl;

  return success;//Return succes.
}

//---------------------------------------------------------------------------------------------------------------

bool University:: CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth,string sGender,int sYearOfStudy, string sMajor, long sAdvisorId){//This function creates a new student if a few conditions are followed.
  if(!checkMajor(sMajor) &&(sMajor != "0"))//If students major does not match any departments then return failure.//Also if students major is "0" then return failure.
    return failure;

  else if(sAdvisorId !=0 && !checkAdvisor(sAdvisorId))//If sAdvisorId = 0 and if the students advisorId doesn't match any faculty ids then return failure.
   return failure;

  student s(sName,sEmail,sAddress,sDateOfBirth,sGender,sYearOfStudy,sMajor,sAdvisorId);//Make an object s of type student.
  Students.push_back(s);// Place it to the end of the vector data structure.
  return success;//Return success.
}

bool University::checkMajor(string sMajor){//This functions will check if the major passed matches any department names.
  for(int i = 0; i < Departments.size(); i++){//Run through each element in the Department vector.
    if(Departments[i].name == sMajor)//If "name" attribute in that certain element equals the major passed, return success.
      return success;
  }
  return failure;//Return failure.
}

bool University::checkAdvisor(long sAdvisorId){//This function will check if the advisorId passed matches any Ids in the Faculties vector.
  for(int i = 0; i < Faculties.size(); i++){//Run through each element of the Faculties vector.
    if(Faculties[i].id == sAdvisorId)//If the id from that certain element of the vector matches the advisorId passed then return succes.
      return success;
  }
  return failure;//Else return failure.
}
//---------------------------------------------------------------------------------------------------------------

bool University:: ListStudents(){//THis function prints out the ID and names of every current student.
  cout<<endl;
  cout<<"------------List of Students------------"<<endl;
  for(int i = 0; i < Students.size();i++){//Run through the Student vector. 
    cout<<"ID: "<<Students[i].id<<endl;
    cout<<"Name: "<<Students[i].name<<endl;
  }
  cout<<"----------------------------------------"<<endl;

}
//---------------------------------------------------------------------------------------------------------------
bool University::ListStudentsOfAFaculty(long facultyId){//This function prints the students from a certain faculty.
  if(!checkFactId(facultyId))
    {
      cout<<"Can not list students of Id#:"<<facultyId<<". ID is invalid"<<endl<<endl;//If the faculty Id passed doesn't match any Ids of a faculty, return failure.
    return failure;
    }

  cout<<"----------List of Students of Faculty#:"<<facultyId<<"-------------"<<endl;
  for(int i = 0; i < Students.size();i++)//Run through Students vector.
    if(Students[i].advisorId == facultyId){//If "advisorId" attribute matches the facultyId passed,then print the following.
      cout<<Students[i].id<<endl;
      cout<<Students[i].name<<endl;
    } 
  cout<<"-------------------------------------------------------"<<endl;
     
  return success;//Return success.
}


bool University::checkFactId(long fFactId){//This function checks if the factulty ID passed is a existing ID.
  for(int i = 0; i < Faculties.size();i++){
    if(Faculties[i].id == fFactId){//Run through Faculties vector. If the id of the element equals the fFatId passed then return success.
      return success;
    }
  }
  return failure;//Else return failure.
}
//---------------------------------------------------------------------------------------------------------------

bool University:: CreateNewCourse(int cMaxSeat,string cName, long cDepId, long cTaughtBy){//This function will create a new course according to the following conditions.
  if(cTaughtBy != 0 && !checkTaughtBy(cTaughtBy)){//If the course is being taught by someone and if it's not valid then print message and return failure.
    cout<<"Cannot create course "<<cName<<"! Faculty doesn't exist!"<<endl;
    return failure;
  }
  else if(!checkDepId(cDepId)){//if the department id passed doesn't exist then print message and return failure.
    cout<<"Department doesn't exist!"<<endl;
    return failure;
  }
  course c(cMaxSeat,cName,cDepId,cTaughtBy);//Create an object c of type course.
  Courses.push_back(c);//Push the object into the Courses vector of type course.
  return success;//Return succes.

}

bool University::checkTaughtBy(long cTaughtBy){//This function will check if the id passed matches the faculties id of each element.
  for(int i = 0; i < Faculties.size(); i++){
    if(Faculties[i].id == cTaughtBy)
      return success;//Return success if so.
  }
  return failure;//Else return failure.
}

//---------------------------------------------------------------------------------------------------------------
bool University::ListCourses(){//This function lists all of the current courses.
  cout<<"------------List of Courses-------------"<<endl;
  for(int i = 0;i <Courses.size();i++){
    Courses[i].print();//Use the print function from class "course".
  }
  cout<<"----------------------------------------"<<endl;
}
//----------------------------------------------------------------------------------------\--------------

bool University:: ListCoursesTaughtByFaculty(long facultyId){//This function will list all courses taught by the faculty Id that's passed.
  if(!checkFactId(facultyId)){//Check in this function if the faculty Id passed is a valid ID.
    return failure;//If not, return failure.
  }

  if(checkFactId(facultyId)){
    cout<<"--List of Courses Taught by Faculty#:"<<facultyId<<"-----------"<<endl;
  for(int j = 0; j < Courses.size();j++){
    if(facultyId == Courses[j].isTaughtBy){//If the id passed matches the "isTaughtBy" attribute, print the following.
      cout<<"Name: "<<Courses[j].name<<"     CRN: "<<Courses[j].CRN<<endl;
    } 
  }
  cout<<"----------------------------------------------------"<<endl;

  }  
  return success;//Return success.
}

//----------------------------------------------------------------------------------------\\--------------
bool University:: ListCoursesOfADepartment(long departId){//This function will list the courses from a certain department.
  if(!checkDepId(departId))//Check if the Id passed is a valid id. If not print message and return failure.
    {
      cout<<"Cannot list courses of ID#:"<<departId<<". Doesn't exist!"<<endl<<endl;
      return failure;//Return failure.
    }
  cout<<"----------Courses of Department#:"<<departId<<"------"<<endl;
  for(int i = 0; i < Courses.size(); i++){//Run through Courses vector.
    if(Courses[i].departId == departId)//If departId from 'i' element matches departId that was passed, then use print function from course class.
      Courses[i].print();
    
  }
  cout<<"------------------------------------------"<<endl;

  return success;//Return success.
}
//----------------------------------------------------------------------------------------\-----------

bool University::ListCoursesTakenByStudent(long studentId){//This function lists the courses taken by a certain student.
  if(!checkStId(studentId))//Return failure if studentId doesn't exist.
    return failure;

  cout<<"------List of Courses taken by Student ID#:"<<studentId<<"-----------"<<endl;
  for(int i = 0; i < Students.size(); i++){//
    if(Students[i].id == studentId){
      for(int j = 0; j < Students[i].coursesTaken.size();j++)
        Students[i].coursesTaken[j].print();//Only printing course ID and Names
    }
  }
  cout<<"---------------------------------------------------------"<<endl;

  return success;
}

bool University:: checkStId(long sStId){//This function checks to see if the id passed matches the certain student id in the student vector.
  for(int i = 0; i < Students.size(); i++){
    if(Students[i].id == sStId)
      return success;//If there's a match, return success.
  }
  return failure;//Else return faillure.
}
//----------------------------------------------------------------------------------------\-----------

bool University::AddACourseForAStudent(long courseId, long stId){//This function will add a course for certain student.
  if(checkAssignedSeats(courseId)){//Check if there are enough seats available to take this class. If not print following message and return failure.
    cout<<"This class seems to be full!"<<endl;
    return failure;
  }
  else if (!checkStId(stId)){//Check if the student Id passed is valid. If not print massage and return failure.
	     cout<<"Student doesn't exist!"<<endl;
	     return failure;
	   }
  else if(!checkCourseId(courseId)){//Check  if the course Id passed is a valid id. If not print following message and return failure.
	     cout<<"Course "<<courseId<<" doesn't exist!"<<endl;
	     return failure;
	   }
  for(int i = 0; i < Students.size();i++){//Run through Students vector.
    if(Students[i].id == stId){//If the id from Students vector in element 'i' equals the student Id passed,proceed.
      for(int j = 0; j < Courses.size();j++)//Run through Courses vector.
	{
	  if(Courses[j].CRN == courseId)//If CRN from Courses vector in element 'i' matches the courseId passed,proceed.
	    {
	      (Students[i].coursesTaken).push_back(Courses[j]);//In coursesTaken in element 'i' of Students vector copy the course into the coursesTaken vector. 
	      Courses[j].assignedSeats++;//Increment assignedSeats by 1.
	    }
	}
    }
  }
  return success;//Return success.
}
	   

bool University:: checkAssignedSeats(long courseId){//This function checks if the assigned seats exceeds the maximum allowed. If not, return success.
  for(int i = 0; i < Courses.size();i++){//Run through Courses vector.
    if(Courses[i].assignedSeats == Courses[i].maxAvailableSeats)//If assignedSeats equals maxAvailableSeats, return success.
      return success;
  }
}

bool University::checkCourseId(long cCRN){//This function checks if the course Id passed is valid or not.
  for(int i = 0; i < Courses.size();i++){
    if(Courses[i].CRN == cCRN)
      {
	if(Courses[i].assignedSeats != Courses[i].maxAvailableSeats)
	  return success;//Return success if they match.
      }
  
  }
  return failure;//Else return failure.
}
//----------------------------------------------------------------------------------------\-----------------------

bool University::DropACourseForAStudent(long courseId, long stId){//This function drops a course from the courseTaken vector in the student class.
  if (!checkStId(stId)){//Check if the student Id passed is a valid id. If not print message and return failure.

    cout<<"Student ID#:"<<stId<<" doesn't exist!"<<endl;
    return failure;
  }
  else if(!checkCourseId(courseId)){//Check if the courseId passed is a valid course. If not print following message and return failure.
    cout<<"Course "<<courseId<<" doesn't exist!"<<endl;
    return failure;
  }
  for(int i = 0; i < (Students[i].coursesTaken).size();i++){//Run through coursesTaken vector within the Student vectr of type student.
    for(int j = 0; j < Courses.size();j++){//GO through the courses.
      if(Courses[j].CRN == courseId){//If the CRN in Courses element 'j' equals the course Id passed....
	(Students[i].coursesTaken).erase((Students[i].coursesTaken).begin() + i);//Delete that course.
	Courses[j].assignedSeats--;//Decrement the number of assigned seats!
      }
    }
  }
  return success;//Return success :)
}

//----------------------------------------------------------------------------------------\-----------------------

bool University::AssignDepartmentChair(long facultyId, long departId){//This function assigns a department chair if few conditions are okay.
  if(!checkDepId(departId)){//Check if the department id passed is valid. If not print message and return failure.
    cout<<"Department #"<<departId<<" doesn't exist!"<<endl;
    return failure;
  }
  else if(!checkFactId(facultyId)){//Check if faculty id passed is valid. If not print message and return failure.
    cout<<"Faculty ID#:"<<facultyId<<" doesn't exist!"<<endl;
    return failure;
  }
  for(int i = 0; i < Departments.size();i++){//Run through Departments vector.
    if(Departments[i].id == departId)//If id from Department element 'i' matches with the passed id set the faculty Id passed to the chairId.
      Departments[i].chairId = facultyId;
    return success;//And return success.
  }

}
//----------------------------------------------------------------------------------------\-----------------------

bool University::AssignInstructorToCourse (long facultyId, long courseId){//This function assigns an instructor to a certain course depending on the id.
  if(!checkFactId(facultyId)){//Check if the facultyid passed is valid. If not print message and return failure.
    cout<<"Faculty ID#:"<<facultyId<<" doesn't exist!"<<endl;
    return failure;
  }
  else if(!checkCourseId(courseId)){//Check If the courseId passed is valid. IF not print messsage and return failure.
    cout<<"Course "<<courseId<<" doesn't exist!"<<endl;
    return failure;
  }

  for(int i = 0; i < Courses.size();i++){//Run through courses vector.
    if(Courses[i].CRN == courseId)//If the CRN attributes from the COurses vector in element 'i' matches the passed courseId set "isTaughtBy = facultyId".
      Courses[i].isTaughtBy = facultyId;//As so.
  }
  return success;//Then return success!.
}
//----------------------------------------------------------------------------------------\-----------------------

bool University:: RemoveADepartment(long depId){//This function removes a department following the following conditions!
  if((!checkDepId(depId))||(checkDepFac(depId))||(checkDepOffCourse(depId))||(checkDepStuMajor(depId)))
    return failure;//If any of those conditions! Then return failure!.

  for(int i = 0; i < Departments.size(); i++){//Run through Departments vector.
    if(Departments[i].id == depId)//If the id attribute from Departments vector in element 'i' matches the passed depId then erase that space!.
      Departments.erase(Departments.begin()+ i);//As so.
  }

  return success;//Then return success...
}

bool University::checkDepFac(long depId){//THis function checks if the faculties department id is a valid department.
  for(int i = 0; i < Faculties.size();i++){
    if(Faculties[i].departId == depId)
      return success;//IF there's a match return succes.
  }
  return failure;//Else return failure.
}

bool University::checkDepStuMajor(long depId){//This function checks the students major 
  string dName;
  for(int i = 0; i < Departments.size(); i++){
    if(Departments[i].id == depId)
      dName = Departments[i].name;//The name from that certain element is placed in dName
  }
  for(int j = 0; j < Students.size(); j++){
    if(dName == Students[j].major)//Comapre the stored name to the sudents major. If there's a match then return success.
      return success;
  }
  return failure;//Else return failure.
}

bool University::checkDepOffCourse(long depId){//This function checks if the depId passed is offerec as a course.
  for(int i = 0; i < Courses.size();i++){
    if(Courses[i].departId == depId)//If there's a match return success!
      return success;
  }
  return failure;//Else this.
}
//----------------------------------------------------------------------------------------

bool University:: RemoveAStudent(long sStId){//This function removes a student
  if(!checkStId(sStId))//If not valid print message and return failure.
    {
      cout<<"Id #:"<<sStId<<" is an invalid ID number! Can't be removed!"<<endl;
      return failure;
    }
  for(int i = 0; i < Students.size();i++){
    if(checkStId(sStId)){
    for(int j = 0; j < (Students[i].coursesTaken).size();j++)
      {
	DropACourseForAStudent((Students[i].coursesTaken[i]).CRN,sStId);//Don't forget to drop the course!
      }
    Students.erase(Students.begin()+i);//Erase the space
    }
  }

  return success;//And return success!
}
//----------------------------------------------------------------------------------------

bool University::RemoveACourse(long cCRN){//This function removes a course following a few conditions .
  if(!checkCourseId(cCRN))//If id number is not valid print message and return failure.
    {
      cout<<"Course ID#:"<<cCRN<<" cannot be removed! Does not exist!"<<endl;
      return failure;
    }
  if(StudentTakingCourse(cCRN))//If a student is still enrolled print message and return faillure.
    {
      cout<<"Course ID#:"<<cCRN<<" cannot be removed! Student is still enrolled!"<<endl;
     return failure; 
    }

  for(int i = 0; i < Courses.size();i++){//Run through courses vector
    if(Courses[i].CRN == cCRN)//If ID's match, erase the space and return success.
      {
	Courses.erase(Courses.begin()+i);
      } 
   
 }
 return success;
}

bool University::StudentTakingCourse(long cCRN){//Checks if a student is taking a certain course depending on ID number.
    for (int j= 0;j<Students.size();j++)
      {
	for(int l=0; l< (Students[j].coursesTaken).size();l++)//We need to counters for 2 different vectors.
	  {
	    if((Students[j].coursesTaken[l]).CRN == cCRN)//If there's a match return success
	      {
		return success;
	      }
	  }
      }
    return failure;//Else return failure.
  }
//----------------------------------------------------------------------------------------

bool University::RemoveAFaculty(long fFactId){//This functions removes a faculty according to the following conditions.
  if(!checkFactId(fFactId)){//If fFactId is invalid print message and return failure.
    cout<<"Faculty ID#:"<<fFactId<<" does not exist! Cannot remove!"<<endl;
    return failure;
  }
  for(int j=0;j<Courses.size();j++){//If any of these checks are true return failure.
      if (fFactId == Courses[j].isTaughtBy)
	return failure;
    }
  
  for(int k=0;k<Students.size();k++){
      if(fFactId == Students[k].advisorId)
	return failure;
    }
  for(int l =0;l<Departments.size();l++){
      if(fFactId == Departments[l].chairId)
	return failure;
    }
  
  for(int m=0; m<Faculties.size();m++){
    if(Faculties[m].id == fFactId)//If these match then erase the space and return success.
	{
	  Faculties.erase(Faculties.begin()+m);
	}
    }
  return success;
}


bool University::ProcessTransactionFile(string fileName)//This function literally proccesses the transaction file.
{
  //Some attributes...
  ifstream fin;
  fin.open(fileName.data());
  string command;
  string depName;
  string depLoc;
  long depChairId;
  long depId;
  string sName;
  string sEmail;
  string sAddress;
  string sDateOfBirth;
  string sGender;
  int sYearOfStudy;
  string sMajor;
  long sAdvisorId;
  long sStId;
  string cName;
  long cDepId;
  long cTaughtBy;
  int cMaxSeat;
  long CRN;
  string fName;
  string fEmail;
  string fAddress;
  string fDateOfBirth;
  string fGender;
  float fSalary;
  int fYearOfExp;
  long fDepId;
  long facultyId;
  if(fin.fail())//If file doesn't open print message and return failure. Filename is hardcoded in.
    {
      cout<<"File does not exist! Check spelling!"<<endl;
      return failure;
    }
  
  while(fin>>command)
    {
      //DO certain action depending on the type of command. Reading in parameters depend on what the command does.
      if(command == "CreateNewDepartment"){
	fin>>depName>>depLoc>>depChairId;
	bool check = CreateNewDepartment(depName,depLoc,depChairId);
       	if(check == success){
	  cout<<"Department " <<depName<<" was successfully added!"<<endl;
	}
	else if(check == failure){
	  cout<<"Department "<<depName<<" cannot be added!"<<endl;
	}
      }
      else if(command == "ListDepartments"){
	cout<<endl;
	bool check =  ListDepartments();
      }
      
      else if(command == "CreateNewFaculty"){
	fin>>fName>>fEmail>>fAddress>>fDateOfBirth>>fGender>>fSalary>>fYearOfExp>>fDepId;
	bool check = CreateNewFaculty(fName,fEmail,fAddress,fDateOfBirth,fGender,fSalary,fYearOfExp,fDepId);
	if(check == success){
	  cout<<"Faculty "<<fName<<" was successfully added!"<<endl;
	}
      	else if(check == failure){
	    cout<<"Faculty "<<fName<<" cannot be added!"<<endl;
	}
      }
	 
	  else if(command == "ListFaculties"){
	    cout<<endl;
	    bool check = ListFaculties();
	  }
    
  else if(command == "ListFacultiesInDepartment"){
    fin>>depId;
    cout<<endl;
    bool check = ListFacultiesInDepartment(depId);
  }

  else if(command =="CreateNewStudent"){//Create New Student
    fin>>sName>>sEmail>>sAddress>>sDateOfBirth>>sGender>>sYearOfStudy>>sMajor>>sAdvisorId;
    bool check = CreateNewStudent(sName,sEmail,sAddress,sDateOfBirth,sGender,sYearOfStudy,sMajor,sAdvisorId);
    if(check == success){      
      cout<<"Student "<<sName<<" was successfully created!"<<endl;
    }
    else
      cout<<"Student "<<sName<<" cannot be added!"<<endl;
  }
 
  else if(command =="ListStudents"){
    bool check = ListStudents();
  }
  
  else if(command =="ListStudentsOfAFaculty"){
    fin>>facultyId;
    bool check = ListStudentsOfAFaculty(facultyId);
  }

  else if(command =="CreateNewCourse"){
    fin>>cName>>cDepId>>cTaughtBy>>cMaxSeat;
    bool check = CreateNewCourse(cMaxSeat,cName,cDepId,cTaughtBy);
    if(check == success){
      cout<<"Course "<<cName<<" has been successfully created!"<<endl;
    }
    else if(check == failure){
      cout<<"Course "<<cName<<" was not created!"<<endl;
    }
  }

  else if(command =="ListCourses"){
    bool check = ListCourses();
  }
  
  else if(command =="ListCoursesTaughtByFaculty"){
    fin>>facultyId;
    bool check = ListCoursesTaughtByFaculty(facultyId);
    if(check==failure)
      cout<<"Cannot list course of Factulty ID:"<<facultyId<<endl<<endl;
  }

  else if(command =="ListCoursesOfADepartment"){
    fin>>depId;
    cout<<"Courses of Department "<<depId<<":"<<endl;
    bool check = ListCoursesOfADepartment(depId);
  }
  else if(command == "AddACourseForAStudent"){
    fin>>CRN>>sStId;
    bool check = AddACourseForAStudent(CRN,sStId);
    if(check == success)
      cout<<"Course "<<CRN<<" was successfully added for "<<sStId<<" student!"<<endl;
    else if(check == failure)
      cout<<"Course "<<CRN<<" cannot be added for "<<sStId<<" student!"<<endl;
  }

  else if(command == "ListCoursesTakenByStudent"){
    fin>>sStId;
    bool check = ListCoursesTakenByStudent(sStId);
  }

  else if(command == "DropACourseForAStudent"){
    fin>>CRN>>sStId;
    bool check = DropACourseForAStudent(CRN,sStId);
    if(check == success)
      {
	cout<<"Course #"<<CRN<<" has been successfully dropped!"<<endl;
      }   
    else if(check == failure)
      {
	cout<<"Course #"<<CRN<<" cannot be dropped!"<<endl;
      }  
  }
  
else if(command =="AssignDepartmentChair"){
    fin>>facultyId>>depId;
    bool check = AssignDepartmentChair(facultyId,depId);
    if(check == success)
      cout<<"Faculty #"<<facultyId<<" was successfully assigned to chair at department #"<<depId<<endl;
    else if(check == failure)
      cout<<"Faculty #"<<facultyId<<" could not be assigned to chair at department #"<<depId<<endl;
  }
 else if(command =="AssignInstructorToCourse"){
   fin>>facultyId>>CRN;
   bool check = AssignInstructorToCourse(facultyId,CRN);
   if(check == success)
     cout<<"Faculty ID#:"<<facultyId<<" was successfully assigned to course#:"<<CRN<<endl;
   else if(check == failure)
     cout<<"Faculty ID#:"<<facultyId<<" can not be assigned to course#:"<<CRN<<endl;



 }
      else if(command == "RemoveADepartment"){
	fin>>depId;
	bool check = RemoveADepartment(depId);
	if(check == success)
	  cout<<"Department ID#:"<<depId<<" was successfully removed!"<<endl;
	else if (check == failure)
	  cout<<"Department ID#:"<<depId<<" can not be removed!"<<endl;
      }
      else if(command == "RemoveAStudent"){//Remove a Student.
	fin>>sStId;
      bool check = RemoveAStudent(sStId);
      if(check == success)
	cout<<"Student was successfully removed!"<<endl;
      else if(check == failure)
	cout<<"Student cannot be removed!!"<<endl;
      }
        
      else if(command == "RemoveACourse"){
	fin>>CRN;
	bool check = RemoveACourse(CRN);
	if(check == success)
          cout<<"Course ID#:"<<CRN<<" was successfully removed!"<<endl;
        else if(check == failure)
          cout<<"Course ID#:"<<CRN<<" cannot be removed!"<<endl;
      }
      else if(command == "RemoveAFaculty"){
	fin>>facultyId;
	bool check = RemoveAFaculty(facultyId);
	if(check == success)
	  cout<<"Faculty ID#:"<<facultyId<<" was successfully removed!"<<endl;
	else if(check == failure)
	  cout<<"Faculty ID#:"<<facultyId<<" cannot be removed!"<<endl;
      }
    }
}
