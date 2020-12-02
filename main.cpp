#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <string>
#include <vector>
#include "Student.hpp"
#include "DomesticStudent.hpp"
#include "ToeflScore.hpp"
#include "InternationalStudent.hpp"
using namespace std;

int main()
{
  unsigned int applicationid = 20200000; //unique applicationid for each student
  
  /////////////////////////// read/write domestic-stu.txt //////////////////////////
  string line;
  ifstream domesticFile("domestic-stu.txt");
  if(!domesticFile.is_open()) 
  {
    //Gives user a warning if the file they would like to use is not opened
    cout << "Unable to open file domestic-stu.txt" << endl;
    return -1;
  }
  //Read the first line of domestic-stu.txt, which specifies
  //the file format. And then print it out to the screen
  getline(domesticFile, line);
  cout << "File format: " << line << endl;

  vector<DomesticStudent> DomesticStudentVector; //vector creation for domestic students file

  while(getline(domesticFile, line))
  {
    istringstream ss(line);

    string firstName, lastName, province, s_cgpa, s_researchScore;
    float cgpa;
    int researchScore;

    //get firstName separated by comma
    getline(ss, firstName, ',');

    //get lastName separated by comma
    getline(ss, lastName, ',');

    //get province separated by comma
    getline(ss, province, ',');

    //get cpga separated by comma, and convert string to float
    getline(ss, s_cgpa, ',');
    cgpa = atof(s_cgpa.c_str());

    //get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());

    //Create new object using constructor
    DomesticStudent newDomesticStudent(firstName, lastName, province, cgpa, researchScore, applicationid);

    //Pass newDomesticStudent object into vector as parameter: custom data type.
    DomesticStudentVector.push_back(newDomesticStudent);
    applicationid++;
  }
  //Closes file after use
  domesticFile.close();
  ///////////////////////////////////////////////////////////////////////////////////////

  /////////////////////////// read/write international-stu.txt //////////////////////////
  //Read the international-stu.txt file and exit if failed
  string line1;
  ifstream internationalFile("international-stu.txt");
  if(!internationalFile.is_open()) {
    cout << "Unable to open file international-stu.txt" << endl;
    return -1;
  }
  //Read the first line of international-stu.txt, which specifies
  //the file format. And then print it out to the screen
  getline(internationalFile, line1);
  cout << "File format: " << line1 << endl;

  //vector creation of international student objects
  vector<InternationalStudent> myInternationalList;
  vector<ToeflScore> myScoreList;

  int stu_count1 = 1;
  while(getline(internationalFile, line)) {
    int i = 0;
    /*process each line, get each field separated by a comma.
    *We use istringstream to handle it.
    *Note in this example code here, we assume the file format
    *is perfect and do NOT handle error cases. We will leave the
    *error and exception handling of file format to Lab Assignment 4
    */
    istringstream ss(line);

    string firstName, lastName, country, s_cgpa, s_researchScore, s_reading, s_listening, s_speaking, s_writing;
    float cgpa;
    int researchScore, reading, listening, speaking, writing, toefl_total;

    getline(ss, firstName, ','); //get firstName separated by comma
    getline(ss, lastName, ','); //get lastName separated by comma
    getline(ss, country, ','); //get province separated by comma
    getline(ss, s_cgpa, ','); //get cpga separated by comma 
    cgpa = atof(s_cgpa.c_str()); //convert cgpa string to float
    getline(ss, s_researchScore, ','); //get researchScore separated by comma
    researchScore = atoi(s_researchScore.c_str()); //convert researchScore to int
    getline(ss, s_reading, ','); //get reading separated by comma
    reading = atoi(s_reading.c_str()); //convert reading to int
    getline(ss, s_listening, ','); //get listening separated by comma
    listening = atoi(s_listening.c_str()); //convert listening to int
    getline(ss, s_speaking, ','); //get speaking separated by comma
    speaking = atoi(s_speaking.c_str()); //convert speaking to int
    getline(ss, s_writing, ','); //get writing separated by comma
    writing = atoi(s_writing.c_str()); //convert writing to int
    toefl_total = reading + listening + speaking + writing; //Add up ToeflScores to get total
        
    //myStudent object creations for each vector index
    InternationalStudent myStudent(firstName, lastName, country, cgpa, researchScore, applicationid);
    myInternationalList.push_back(myStudent); //copies variables into current student obj

    //myScores object creations for each vector index
    ToeflScore myScores(reading, listening, speaking, writing, toefl_total);
    myScoreList.push_back(myScores); //copies variables into current scores obj

    applicationid++;
    stu_count1++;
    i++;
  }
  internationalFile.close();
  ///////////////////////////////////////////////////////////////////////////////////////


  int function = true;
  cout << "\n\nWelcome to the SFU graduate student admission system! Please select an option below:\n";
  
  while (function == true) {
    int functionchoice_1; 
    cout << "\nWould you like to see the...\nDomestic? type 1. \nInternational? type 2. \nor to exit the program? type 0.  \n";
    cin >> functionchoice_1;

    if (functionchoice_1 == 1) {
      int compareCGPA, compareResearchScore, compareLastName, compareFirstName;
      DomesticStudent studentobject;
      studentobject.DomesticStudentOutput(compareCGPA, compareResearchScore, compareLastName,compareFirstName, DomesticStudentVector);
    }
    else if (functionchoice_1 == 2 ) {
      //Menu prompt for user choice
      bool menu = true;
      int option;
      InternationalStudent temp;

      while(menu == true) 
      {
        cout << "1 : Print out international-stu.txt\n2 : Sort by First Names\n3 : Sort by Last Names\n4 : Sort by CGPA\n5 : Sort by ResearchScore\n6 : Overall sort\n7 : Go back to main menu\n";
        cin >> option;

        if(option == 1) { ///print out entire international students file
          for(int i = 0; i < myInternationalList.size(); i++) {
            cout << "--------------- International Student #" << i + 1 << " ---------------\n";
            cout << myInternationalList[i] << myScoreList[i] << endl;
          }
        }
        else if(option == 2) { //sort international by first names (A-Z)
          for(int i = 0; i < myInternationalList.size(); i++) {
            for(int j = i + 1; j < myInternationalList.size(); j++) {
              int output = compareFirstName(myInternationalList[i], myInternationalList[j]);
              if(output == 1) 
              {
                temp = myInternationalList[i];
                myInternationalList[i] = myInternationalList[j];
                myInternationalList[j] = temp;

                ToeflScore tempScore;
                tempScore = myScoreList[i];
                myScoreList[i] = myScoreList[j];
                myScoreList[j] = tempScore;
              }
            }
          }
          for(int i = 0; i < myInternationalList.size(); i++) {
            cout << "--------------- International Student #" << i + 1 << " ---------------\n";
            cout << myInternationalList[i] << myScoreList[i];
          }
        }
        else if(option == 3) { //sort international by last names (A-Z)
          for(int i = 0; i < myInternationalList.size(); i++) {
            for(int j = i + 1; j < myInternationalList.size(); j++) {
              int output = compareLastName(myInternationalList[i], myInternationalList[j]);
              if(output == 1) 
              {
                temp = myInternationalList[i];
                myInternationalList[i] = myInternationalList[j];
                myInternationalList[j] = temp;

                ToeflScore tempScore;
                tempScore = myScoreList[i];
                myScoreList[i] = myScoreList[j];
                myScoreList[j] = tempScore;
              }

            }
          }

          for(int i = 0; i < myInternationalList.size(); i++) {
            cout << "--------------- International Student #" << i + 1 << " ---------------\n";
            cout << myInternationalList[i] << myScoreList[i];
          } 
        }
        else if(option == 4) { //sort international students by CGPA (high-to-low)
          for(int i = 0; i < myInternationalList.size(); i++) {
            for(int j = i + 1; j < myInternationalList.size(); j++) {
              int output = compareCGPA(myInternationalList[i], myInternationalList[j]);
              if(output == 1) 
              {
                temp = myInternationalList[i];
                myInternationalList[i] = myInternationalList[j];
                myInternationalList[j] = temp;

                ToeflScore tempScore;
                tempScore = myScoreList[i];
                myScoreList[i] = myScoreList[j];
                myScoreList[j] = tempScore;
              }

            }
          }
          for(int i = myInternationalList.size() - 1; i >= 0; i--) {
            cout << "--------------- International Student #" << myInternationalList.size() - i << " ---------------\n";
            cout << myInternationalList[i] << myScoreList[i];
          }
        }
        else if(option == 5) { //sort international students by ResearchScore (high-to-low)
          for(int i = 0; i < myInternationalList.size(); i++) {
            for(int j = i + 1; j < myInternationalList.size(); j++) {
              int output = compareResearchScore(myInternationalList[i], myInternationalList[j]);
              if(output == 1) 
              {
                temp = myInternationalList[i];
                myInternationalList[i] = myInternationalList[j];
                myInternationalList[j] = temp;

                ToeflScore tempScore;
                tempScore = myScoreList[i];
                myScoreList[i] = myScoreList[j];
                myScoreList[j] = tempScore;
              }
            }
          }
          for(int i = myInternationalList.size() - 1; i >= 0; i--) {
            cout << "--------------- International Student #" << myInternationalList.size() - i << " ---------------\n";
            cout << myInternationalList[i] << myScoreList[i];
          } 
        }
        else if(option == 6) { //overall sort the international student text file
          for(int i = 0; i < myInternationalList.size(); i++) {
            for(int j = i + 1; j < myInternationalList.size(); j++) {
              int output = compareResearchScore(myInternationalList[i], myInternationalList[j]);
              if(output == 1) 
              {
                temp = myInternationalList[i];
                myInternationalList[i] = myInternationalList[j];
                myInternationalList[j] = temp;

                ToeflScore tempScore;
                tempScore = myScoreList[i];
                myScoreList[i] = myScoreList[j];
                myScoreList[j] = tempScore;
              }
              else if(output == 0) {
                int output2 = compareCGPA(myInternationalList[i], myInternationalList[j]);
                if(output2 == 1) {
                  temp = myInternationalList[i];
                  myInternationalList[i] = myInternationalList[j];
                  myInternationalList[j] = temp;

                  ToeflScore tempScore;
                  tempScore = myScoreList[i];
                  myScoreList[i] = myScoreList[j];
                  myScoreList[j] = tempScore;
                }
                else if(output2 == 0) {
                  InternationalStudent iTemp;
                  int output3 = iTemp.compareCountry(myInternationalList[i].get_country(), myInternationalList[j].get_country());
                  if(output3 == -1) {
                    temp = myInternationalList[i];
                    myInternationalList[i] = myInternationalList[j];
                    myInternationalList[j] = temp;

                    ToeflScore tempScore;
                    tempScore = myScoreList[i];
                    myScoreList[i] = myScoreList[j];
                    myScoreList[j] = tempScore;
                  }
                }
              }
            }
          }
          for(int i = myInternationalList.size() - 1; i >= 0; i--) {
            if(myScoreList[i].ToeflCondition()) {
              cout << "--------------- International Student #" << myInternationalList.size() - i << " ---------------\n";
              cout << myInternationalList[i] << myScoreList[i];
            }
          }       
        }  
        else if(option == 7) { //Go back to main menu
          cout << endl;
          menu = false;
        }
        else { //return a warning and to the main menu of the program
          cout << "This is not a menu option\n";
        }
      }
    }

    else if (functionchoice_1 == 0)
    {
      cout<<"Buh-bye \n";
      exit(1);
    }
    else {
      cout<<"That is not a valid?  \n";
      cout<<"Please retry the input\n";
    }
  }
}


//Can be used to view individual students.
/*
/////////////////////////////////////////////////////////////////////////
    else if(option == 8) { //TESTING PURPOSES
      int x = -1;
      cout << "Input the desired domestic student info you would like to get: ";
      cin >> x;
      x -= 1;
      cout << myInternationalList[x];
    }
    else if(option == 9) { //TESTING PURPOSES
    int x = -1;
    cout << "Input the desired international student info you would like to get: ";
    cin >> x;
    x -= 1;
    ToeflScore myScores;
      if(myScoreList[x].negateToefl(myScores) == false) {
        cout << "\nThis student did not meet the minimum ToeflScore.\n\n";
      }
      else if(myScoreList[x].negateToefl(myScores) == true) {
        cout << myInternationalList[x] << myScoreList[x];
      }
    }
    else if(option == 10) { //TESTING PURPOSES
    int x = -1;
    cout << "Input the desired student info you would like to get: ";
    cin >> x;
    x -= 1;
    cout << myInternationalList[x];
    }
/////////////////////////////////////////////////////////////////////////
*/