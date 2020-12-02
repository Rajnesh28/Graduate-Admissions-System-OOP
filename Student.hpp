#include <string>
#include <vector>
#include <iomanip>
#include <ostream>
using namespace std;
#ifndef STUDENT_H //Student Header
#define STUDENT_H

class Student
{
  private:
    //Declarations
    string firstname;
    string lastname;
    float cgpa;
    int researchscore;
    int applicationid;

  public:
    //Constructors
    //Student(string firstname, string lastname, float cgpa, int researchscore, int applicationid);
    Student();

    //Destructors
    ~Student();

    //Friend Functions
    friend int compareFirstName(Student &a, Student &b);
    friend int compareLastName(Student &a, Student &b);
    friend int compareCGPA(Student &a, Student &b);
    friend int compareResearchScore(Student &a, Student &b);

    friend void testFunction(Student &test);

    //Compare functions
    //int compareFirstName(string firstnameone, string firstnametwo);
    int compareLastName(string lastnameone, string two);
    int compareCGPA(float cpgaOne, float cpgaTwo);
    int compareResearchScore(int one, int two);

    //Accessors
    string get_firstname();
    string get_lastname();
    float get_cgpa();
    int get_researchscore();
    int get_applicationid();

    //Mutators
    void set_firstname(string firstname);
    void set_lastname(string lastname);
    void set_cgpa(float cgpa);
    void set_researchscore(int researchscore);
    void set_applicationid(int applicationid);

};
#endif