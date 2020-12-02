#include <string>
#include <vector>
#include "Student.hpp"
#ifndef DOMESTICSTUDENT_H //Domestic header
#define DOMESTICSTUDENT_H

class DomesticStudent: public Student
{

  public:
  //Constructor
  DomesticStudent();
  DomesticStudent(string firstname, string lastname, string province, float cgpa, int researchscore, int applicationid);

  //Destructor 
  ~DomesticStudent();

  int i, j;
  
  //Accesor function
  string get_province();

  //Mutator function
  void set_province(string province);

  // Comparison Functions for province
  void compareProvince(vector<DomesticStudent>& DomesticStudentVector);

  //Comparison Functions for overall
  int compareProvince_ini(DomesticStudent &a, DomesticStudent &b);
  int compareCGPA_ini(DomesticStudent &a, DomesticStudent &b);
  int compareResearchScore_ini(DomesticStudent &a, DomesticStudent &b);
  int compareLastName_ini(DomesticStudent &a, DomesticStudent &b);


  //Overloaded Operator to display object information
  friend ostream& operator<<(ostream& out, DomesticStudent& newDomesticStudent);

  //Function to implement for DomesticStudent
  int DomesticStudentOutput(int compareCGPA, int compareResearchScore, int compareLastName, int compareFirstName, vector<DomesticStudent>& DomesticStudentVector);
  
  //Initalize vectors
  vector<DomesticStudent> DomesticStudentVector;

  private:
  
  //Province variable declaration 
  string province;


};


#endif