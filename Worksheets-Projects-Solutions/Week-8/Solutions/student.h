/*
  Problem:
  - Using the FCylinder worksheet from last week and any other classes resources, 
    create a Student class. 
*/

#include <iostream>

using namespace std;

class Student
{
    int id;                                
    float grade;                           
    string name;                           
    
  public:
    // constructors/destructors
    Student();                             
    Student(int i, float g, string n);     
    Student(const Student& s);    
    ~Student();                            
    
    // getters (good to have for each member variable)
    int getID();                           
    float getGrade();                      
    string getName();                      
    
    // setters (good to have for each member variable)
    void setID(int i);                     
    void setGrade(float g);                
    void setName(string n);                
    
    // miscellaneous methods (those not constructors/destructors, getters, or setters)
    void printSelf();                      // required
    char getLetterGrade();                 // required
};

// constructors/destructors
Student::Student()
{
  // just an example of an average Derek
  id = 420;
  grade = 69.50;
  name = "Derek";
}

Student::Student(int i, float g, string n)
{
  // for validation
  setID(i);
  setGrade(g);
  setName(n);
}


Student::Student(const Student& s)
{
  id = s.id;
  grade = s.grade;
  name = s.name;
}


Student::~Student()
{
  cout << "Exterminated student with id: " << id << endl;
}
/*-----------------------------------------------------------------------------------------*/   
// getters
int Student::getID()
{
  return id;
}

float Student::getGrade()
{
  return grade;
}

string Student::getName()
{
  return name;
}
/*-----------------------------------------------------------------------------------------*/       
// setters
void Student::setID(int i)
{
  if(0 <= i)
  {
    id = i;
  }
  else
  {
    cout << "ERROR: Invalid ID number given (must be greater than or equal to 0).\n";
  }
}

void Student::setGrade(float g)
{
  if(0 <= g && g <= 100)
  {
    grade = g;
  }
  else
  {
    cout << "ERROR: Grade given is not within valid bounds (must be between 0 to 100).\n";
  }
}

void Student::setName(string n)
{
  name = n;
}
/*-----------------------------------------------------------------------------------------*/   

// miscellaneous methods
void Student::printSelf()
{
  cout << "Student name: " << name 
       << "\nStudent ID: " << id
       << "\nStudent grade: " << grade
       << endl;
}

char Student::getLetterGrade()
{
  // annoying, but makes things easier in the long run
  if(grade <= 0 && grade < 60.0)
  {
    return 'F';
  }
  else if(grade <= 60.0 && grade < 70.0)
  {
    return 'D';
  }
  else if(grade <= 70.0 && grade < 80.0)
  {
    return 'C';
  }
  else if(grade <= 80.0 && grade < 90.0)
  {
    return 'B';
  }
  else // remember that the grade is assumed valid here
  {
    return 'A';
  }
}


