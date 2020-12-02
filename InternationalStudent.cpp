#include "InternationalStudent.hpp"
#include <cstring>

//Constructors
InternationalStudent::InternationalStudent(string firstname, string lastname, string country, float cgpa, int researchscore, unsigned int applicationid) {
  //Precondition: Takes two strings for first and last names, a string for country, a float for cgpa, an integer for research score and another unsigned integer for application id
  //Postcondition: Uses the set functions to set the values for the first and last names, country, cgpa, research score, and application id
  set_firstname(firstname);
  set_lastname(lastname);
  set_country(country);
  set_cgpa(cgpa);
  set_researchscore(researchscore);
  set_applicationid(applicationid);
}

//Default Constructor
InternationalStudent::InternationalStudent() {}

//Destructor
InternationalStudent::~InternationalStudent() {}

//Overload operator << definition
ostream& operator<<(ostream& out, InternationalStudent& myStudent) {
  out << myStudent.get_firstname() << " " << myStudent.get_lastname() << " from " << myStudent.get_country() << ", CGPA: " << setprecision(2) << myStudent.get_cgpa() << ", ResearchScore: " << myStudent.get_researchscore() << ", ApplicationID: " << myStudent.get_applicationid() << "\n";
  return out;
}

//Setters
void InternationalStudent::set_country(string country) {
  this->country = country;
}

//Getters
string InternationalStudent::get_country() {
  return country;
}

//Functions
// return 0 if both strings are equal, -1 if first string is less than the second, else 1
int InternationalStudent::compareCountry(string country1, string country2) {
  //Precondition: Two string input values
  //country1 is the first student's country we are comparing and counry two is the second student's country we are comparing here
  //Postcondition: Compared the letters in the two countries names until it finds two different letters in the same position of the two country names
  //Returns a positive 1 if country1 is alphabetically larger than country2
  //Otherwise returns a negative 1 if country1 is alphabetically smaller than country2
  int output = 0;
  for(int i = 0; i < country1.length(); i++) {
    if((country1[i]) == (country2[i])) {
      continue;
    }
    else if((country1[i]) > (country2[i])) {
      output = 1;
      break;
    }
    else if((country1[i]) < (country2[i])) {
      output = -1;
      break;
    }
  }
  return output;
}
