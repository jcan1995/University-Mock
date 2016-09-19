#ifndef A3_UNIVERSITY_H
#define A3_UNIVERSITY_H

#include "A3_Department.h"//Include all this header files since we will be utilizing their attributes here.
#include "A3_Student.h"
#include "A3_Course.h"
#include "A3_Faculty.h"
#include <string>
using namespace std;

class University
{

 protected:
  vector<department> Departments;//A vector of type department.
  vector<student> Students;//A vector of type student.
  vector<course> Courses;//A vector of type course.
  vector<faculty> Faculties;//A vector of type faculty.
  static bool failure;//Static members 
  static bool success;


 public:
  // University();
  // ~University();
  //Functions accepting parameters depending on their jobs
  bool CreateNewDepartment(string depName, string depLoc, long depChairId);
  bool StudentTakingCourse(long cCRN);
  bool checkDepChairId(long depChairId);
  bool RemoveADepartment(long depId);
  bool checkDepId(long depId);
  bool CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender,int sYearOfStudy, string sMajor, long sAdvisorId);
  bool checkMajor(string sMajor);
  bool checkAdvisor(long sAdvisorId);  

  bool RemoveAStudent(long sStId);
  bool checkStId(long sStId);
 
  bool CreateNewCourse(int cMaxSeat,string cName, long cDepId, long cTaughtBy);
  bool checkTaughtBy(long cTaughtBy);

  bool RemoveACourse(long cCRN);
  
  bool CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender,float fSalary, int fYearOfExp, long fDepId);
  bool checkCourseId(long cCRN);
  bool checkDepFac(long depId);
  bool checkDepOffCourse(long depId);
  bool checkDepStuMajor(long depId);
  bool RemoveAFaculty(long fFactId);
  bool checkFactId(long fFactId);
  bool checkFacCourse(long fFactId);
 
  bool ListCoursesTaughtByFaculty(long facultyId);
  bool ListCoursesTakenByStudent(long studentId);
  bool ListFacultiesInDepartment (long departId);
  bool ListStudentsOfAFaculty(long facultyId);
  bool ListCoursesOfADepartment(long departId);
  bool AddACourseForAStudent(long courseId, long stId);
  bool checkAssignedSeats(long courseId);
  bool DropACourseForAStudent(long courseId, long stId);
  bool AssignDepartmentChair(long facultyId, long departId);  
  bool AssignInstructorToCourse (long facultyId, long courseId);
  
  bool ListDepartments();
  bool ListStudents();
  bool ListCourses();
  bool ListFaculties();

  
  bool ProcessTransactionFile(string fileName);
};

#endif
