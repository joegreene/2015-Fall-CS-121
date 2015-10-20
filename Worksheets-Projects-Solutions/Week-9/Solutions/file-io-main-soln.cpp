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

void load_from_file(string fn, Student arr[], int& cnt, const int CAP)
{
  ifstream infile;
  infile.open(fn.c_str());
  
  if(infile.is_open())
  {
    // load from file
    string name;
    int id;
    float grade;
    
    while( (infile >> name >> id >> grade) && cnt < CAP )
    {
      arr[cnt].setName(name);
      arr[cnt].setID(id);
      arr[cnt].setGrade(grade);
      cnt++;
    }
    
    infile.close(); // close file when done with it
  }
  else
  {
    cout << "ERROR: Could not load student data from filename supplied!\n"
         << "The format required is the following: \n"
         << "\nNAME"
         << "\nID"
         << "\nGRADE"
         << "\n... more entries ...\n"
         << "\nTerminating program...\n\n";
  }
}

// to-do
void find_student(Student arr[], int cnt)
{
  string str_input, name_input;
  int i, id_input;
  
  cout << "Please select to search by id (id) or name (name): ";
  cin >> str_input;
  
  if( str_input == "id" )
  {
    cout << "Please enter the id of the student you wish to find: ";
    cin >> id_input;
    
    for(i = 0; i < cnt; ++i)
    {
      if( id_input == arr[i].getID() )
      {
        cout << "Found student with the following details: \n\n";
        arr[i].printSelf();
        break;
      }
    }
    
    if( i == cnt )
    {
      cout << "Student not found in list.";
    }
  }
  else if( str_input == "name" )
  {
    cout << "Please enter the name of the student you wish to find (no spaces): ";
    cin >> name_input;
    
    for(i = 0; i < cnt; ++i)
    {
      if( name_input == arr[i].getName() )
      {
        cout << "Found student with the following details: \n\n";
        arr[i].printSelf();
        break;
      }
    }
    
    if( i == cnt )
    {
      cout << "Student not found in list.";
    }
  }
  else
  {
    cout << "ERROR: Invalid choice! Returning to main menu...";
  }
  
}

// to-do
void print_list(Student arr[], int cnt)
{
  for(int i = 0; i < cnt; ++i)
  {
    arr[i].printSelf();
  }
}
