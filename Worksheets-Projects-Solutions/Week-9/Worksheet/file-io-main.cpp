#include "student.h"
#include <fstream>  // required for file io

// function prototypes
void displayMenu();
void load_from_file(string fn, Student arr[], int& cnt, const int CAP);
void find_student(Student arr[], int cnt);                             
void print_list(Student arr[], int cnt);                               

int main()
{
  const int STUDENT_CAP = 30;            // maximum # of students in a class
  int input = -1,                        // for user input
      cnt = 0;                           // # of elements in student_list
  string filename = "student_data.txt";  // filename for load
  Student student_list[STUDENT_CAP];     // student list
  
  enum { FIND = 1, PRINT, QUIT };
  
  // load from file first
  load_from_file(filename, student_list, cnt, STUDENT_CAP);
  
  // only run the program if the file was able to be read from
  if(cnt > 0)
  {
    do
    {
      displayMenu();
      cin >> input;
      
      switch(input)
      {
        case FIND:
          find_student(student_list, cnt);
          break;
        case PRINT:
          print_list(student_list, cnt);
        case QUIT:
          break;
        default:
          cout << "ERROR: Invalid input given!";
      }
      cout << "\n\n";
    }while( input != QUIT );
  }
    
  return 0;
}

// fancy-shmancy menu for this program
void displayMenu()
{
  cout << "Student Program:"
       << "\n------------------------------"
       << "\n1. Find student in student list."
       << "\n2. Print student list."
       << "\n3. Quit program."
       << "\nEnter choice: ";
}


