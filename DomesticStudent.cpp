#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <cmath> //mathematical operations

//Necessary header files to include
#include "Student.hpp"
#include "DomesticStudent.hpp"

using namespace std;

//Constructor function
DomesticStudent::DomesticStudent()
{
  //Do nothing
}

//Copy constructor function
DomesticStudent::DomesticStudent(string firstname, string lastname, string province, float cgpa, int researchscore, int applicationid)
{
  //Precondition: Takes two strings for first and last names, a string for country, a float for cgpa, an integer for research score and another unsigned integer for application id
  //Postcondition: Uses the set functions to set the values for the first and last names, country, cgpa, research score, and application id
  set_firstname(firstname);
  set_lastname(lastname);
  set_cgpa(cgpa);
  set_researchscore(researchscore);
  set_province(province);
  set_applicationid(applicationid);
}

//Deconstrcutor function
DomesticStudent::~DomesticStudent()
{
  //Do Nothing
}

//Accessor Functions
void DomesticStudent::set_province(string province)
{
  this->province = province;
}

//Mutator Functions
string DomesticStudent::get_province()
{
  return province;
}

//Function that returns the student values
int DomesticStudent::DomesticStudentOutput(int compareCGPA, int compareResearchScore, int compareLastName, int compareFirstName, vector<DomesticStudent>& DomesticStudentVector)
{
  //Precondition: takes intiger values for the compared CGPA, comapred research score, compared last name and compared first name
  //Postcondition: outputs sorted lists and values based on user input

  //Retrieves user intput and choice
  int domestic_choice1, domestic_choice2;
  bool dm = true;
  cout<<endl;
  while(dm == true) {
    cout<<"\nWould you like to view the ENTIRE list? Type 1\n";
    cin>>domestic_choice1;
    if (domestic_choice1 == 1)
    {
      //If user chooses one then the entire list will be printed through a for loop
      for(int i=0; i < DomesticStudentVector.size(); i++) {
        cout << "--------------- Domestic Student #" << i + 1 << " ---------------\n" << DomesticStudentVector[i];
      }

      cout<<"___________________________________________________________\n";
      cout<<"Would you like to organize the list?\n ";
      cout<<"By firstname, type 1? \n";
      cout<<"By lastname, type 2? \n";
      cout<<"By CGPA, type 3? \n";
      cout<<"By Province, type 4? \n";
      cout<<"By ResearchScore, type 5? \n";
      cout<<"By Overall Sorting, type 6? \n";

      //Retrieves user input and choice based on the above choices
      cin>>domestic_choice2;

      //Sort by Firstname
      if (domestic_choice2 == 1) 
      {
        for (int i = 0; i < DomesticStudentVector.size(); i++) 
        {
          for (int j = i + 1; j < DomesticStudentVector.size(); j++) 
          {
            if (DomesticStudentVector[i].get_firstname() > DomesticStudentVector[j].get_firstname()) 
            {
              DomesticStudent temp = DomesticStudentVector[i];
              DomesticStudentVector[i] = DomesticStudentVector[j];
              DomesticStudentVector[j] = temp;
            }
          }
        }
        for(int i=0; i < DomesticStudentVector.size(); i++) {
          cout << "--------------- Domestic Student #" << i + 1 << " ---------------\n" << DomesticStudentVector[i];
        }
      }

      //Sort by Lastname
      else if (domestic_choice2 == 2) {
        for (int i = 0; i < DomesticStudentVector.size(); i++) {
          for (int j = i + 1; j < DomesticStudentVector.size(); j++) {
            if (DomesticStudentVector[i].get_lastname() > DomesticStudentVector[j].get_lastname()) {
              DomesticStudent temp = DomesticStudentVector[i];
              DomesticStudentVector[i] = DomesticStudentVector[j];
              DomesticStudentVector[j] = temp;
            }
          }
        }
        for(int i=0; i < DomesticStudentVector.size(); i++) {
          cout << "--------------- Domestic Student #" << i + 1 << " ---------------\n" << DomesticStudentVector[i];
        }
      }

      //Sort by CGPA
      else if (domestic_choice2 == 3) {
        for (int i = 0; i < DomesticStudentVector.size(); i++) {
          for (int j = i + 1; j < DomesticStudentVector.size(); j++) {
            if (DomesticStudentVector[i].get_cgpa() > DomesticStudentVector[j].get_cgpa()) {
              DomesticStudent temp = DomesticStudentVector[i];
              DomesticStudentVector[i] = DomesticStudentVector[j];
              DomesticStudentVector[j] = temp;
            }
          }
        }
        for (int i = DomesticStudentVector.size() - 1; i >= 0; i--) {
          cout << "--------------- Domestic Student #" << DomesticStudentVector.size() - i << " ---------------\n" << DomesticStudentVector[i];
        }
      }
      
      //Sort by province
      else if (domestic_choice2 == 4) {
        compareProvince(DomesticStudentVector);
        for(int i=0; i < DomesticStudentVector.size(); i++) {
          cout << "--------------- Domestic Student #" << i + 1 << " ---------------\n" << DomesticStudentVector[i];
        }
      }

      //Sort by Research Score
      else if (domestic_choice2 == 5) {
        for (int i = 0; i < DomesticStudentVector.size(); i++) {
          for (int j = i + 1; j < DomesticStudentVector.size(); j++) {
            if (DomesticStudentVector[i].get_researchscore() > DomesticStudentVector[j].get_researchscore()) {
              DomesticStudent temp = DomesticStudentVector[i];
              DomesticStudentVector[i] = DomesticStudentVector[j];
              DomesticStudentVector[j] = temp;
            }
          }
        }
        for (int i = DomesticStudentVector.size() - 1; i >= 0; i--) {
          cout << "--------------- Domestic Student #" << DomesticStudentVector.size() - i << " ---------------\n" << DomesticStudentVector[i];
        }
      }

      

      ////////////////////////////////////////////////////////////////////////////////////////////////////////////
      //overall sort the Domestic Student text file
      else if (domestic_choice2 == 6) {
        DomesticStudent temp;
        for(int i = 0; i < DomesticStudentVector.size(); i++) {
          for(int j = i + 1; j < DomesticStudentVector.size(); j++) {
            int output = compareResearchScore_ini(DomesticStudentVector[i], DomesticStudentVector[j]);
            if(output == 1) {
              temp = DomesticStudentVector[i];
              DomesticStudentVector[i] = DomesticStudentVector[j];
              DomesticStudentVector[j] = temp;
            }
            else if(output == 0) {
              int output2 = compareCGPA_ini(DomesticStudentVector[i], DomesticStudentVector[j]);
              if(output2 == 1) {
                temp = DomesticStudentVector[i];
                DomesticStudentVector[i] = DomesticStudentVector[j];
                DomesticStudentVector[j] = temp;
              }
              else if(output2 == 0) {
                DomesticStudent iTemp;
                int output3 = compareProvince_ini(DomesticStudentVector[i], DomesticStudentVector[j]);
                if(output3 == -1) {
                  temp = DomesticStudentVector[i];
                  DomesticStudentVector[i] = DomesticStudentVector[j];
                  DomesticStudentVector[j] = temp;
                }
              }
            }
          }
        }
        for(int i = DomesticStudentVector.size() - 1; i >= 0; i--) {
          cout << "--------------- Domestic Student #" << DomesticStudentVector.size() - i << " ---------------\n" << DomesticStudentVector[i];
        }
      }
      else {
          cout<< "\nThat is an invalid input! Please retry \n";
      }
      dm = false;
    }
    else 
    {
      cout<< "\nOkay Sathish/Xingyu, there's only one number you can type! \n";
    }
  }
  return 0;
}
      
////////////////////////////////////////// compareProvince /////////////////////////////////////////////////////
void DomesticStudent::compareProvince(vector<DomesticStudent>& DomesticStudentVector)
{
  //Precondition: takes vector values only
  //Postcondition: Turns the province in the next position after the same as the province in the position before it
  for (int j = 0; j < DomesticStudentVector.size(); j++)
  {
    for (int k = 0; k < DomesticStudentVector.size(); k++)  
    {
      
      if (DomesticStudentVector[k].get_province() > DomesticStudentVector[k + 1].get_province())
      {
        DomesticStudent temp = DomesticStudentVector[k];
        DomesticStudentVector[k] = DomesticStudentVector[k+1];
        DomesticStudentVector[k+1] = temp;
      }
    }
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Overload operator << definition
ostream& operator<<(ostream& out, DomesticStudent& newDomesticStudent) 
{ 
  out <<" Firstname: " << newDomesticStudent.get_firstname()
      <<" | Lastname: "<< newDomesticStudent.get_lastname()
      <<" | with a CGPA of: "<< setprecision(2) << newDomesticStudent.get_cgpa()
      <<" | from Province: "<< newDomesticStudent.get_province()
      <<" | and a Research Score of: "<< newDomesticStudent.get_researchscore()<<"\n"
      <<" | Application ID " << newDomesticStudent.get_applicationid()<<endl<<endl;
      return out;
}


// Compare first name function //
int DomesticStudent::compareProvince_ini(DomesticStudent &a, DomesticStudent &b) 
{
  //Precondition: Two different string values are inputed
  //province is the first province name  and province name two is the second last name
  //Postcondition: Comapared the two last names until it found a different letter for both in the same position
  //If the letter for province is alphabetically after the letter for province return a positive 1 otherwise it will return a negative 1

  int output = 0;
  
  string one = a.get_province();
  string two = b.get_province();

  for(int i = 0; i < one.length(); i++) 
  {
    one[i] = tolower(one[i]);
  }
  for(int i = 0; i < two.length(); i++) 
  {
    two[i]  = tolower(two[i]);
  }

  for(int i = 0; i < a.get_province().length(); i++) {
    if(one[i] == two[i])
    {
      continue;
    }
    else if(one[i] > two[i]) 
    {
      output = 1;
      break;
    }
    else if(one[i] < two[i]) {
      output = -1;
      break;
    }
    if(i == one.length() - 1 && two.length() > one.length()) {
      output = -1;
    }
    else if(i == one.length() - 1 && two.length() < one.length()){
      output = 1;
    }

  }
  return output;
}


int DomesticStudent::compareResearchScore_ini(DomesticStudent &a, DomesticStudent &b)
{

//Compare researchscore function to obtain
//Valid sorting when called in the function itself
//Calls function parameters and returns integer
  if(a.get_researchscore() > b.get_researchscore()) 
  {
    return 1;
  }
  else if(a.get_researchscore() < b.get_researchscore()) 
  {
    return -1;
  }
  else 
  {
    return 0;
  }
}

int DomesticStudent::compareCGPA_ini(DomesticStudent &a, DomesticStudent &b) 
{
  //Precondition: Two different float values are inputed
  //cgpaOne is the first CGPA and cgpaTwo is the second CGPA
  //Postcondition: Comapared the two CGPA values
  //If cgpaOne is numerically greater than cgpaTwo return a postive 1 otherwise it will return a negative 1
  if(a.get_cgpa() > b.get_cgpa()) 
  {
    return 1;
  }
  else if(a.get_cgpa() < b.get_cgpa()) 
  {
    return -1;
  }
  else 
  {
    return 0;
  }
}
