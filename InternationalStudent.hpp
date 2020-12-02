#include "Student.hpp"
#ifndef INTERNATIONALSTUDENT_H
#define INTERNATIONALSTUDENT_H

class InternationalStudent: public Student
{
  private:
    //Declarations
    string country;

  public:
    //Constructors
    InternationalStudent(string firstname, string lastname, string country, float cgpa, int researchscore, unsigned int applicationid);
    InternationalStudent(); //default

    //Destructors
    ~InternationalStudent();

    //Overloaded Operator
    friend ostream& operator<<(ostream& out, InternationalStudent& myStudent);

    //Functions
    int compareCountry(string country1, string country2);

    //Mutators
    void set_country(string country);

    //Accessors
    string get_country();
};
#endif