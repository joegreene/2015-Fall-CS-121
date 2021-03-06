#include "student.h"

/*
  The following notes are used as a guideline for testing purposes:
  1. Creating a Student with no arguments, with arguments, and from an existing Student
  2. Create a list of 5 Student (which represents a small classroom)
  3. Give unique and complete information to each student of the list
  4. Print each student's (in the list) information
  5. Print the letter grade of each student (in the list).
*/

int main()
{
  // 1. Creating a Student with no arguments, with arguments, and from an existing Student
  Student s1;
  Student s2(1234, 77.7, "George Costanza");
  Student s3(s2);
  
  // 2. Create a list of 5 Student (which represents a small classroom)
  Student student_list[5];
  
  // 3. Give unique and complete information to each student of the list
  for(int i = 0; i < 5; ++i)
  {
    student_list[i].setID(i+1000);                           // making mine work as 1000, 1001, 1002, etc.
    student_list[i].setName("Unique name " + to_string(i));  // C++11 code 
    student_list[i].setGrade(i * 20);                        // just for testing
  }
  
  // 4. Print each student's (in the list) information
  cout << "Student list:\n"
       << "-------------\n";
  for(int i = 0; i < 5; ++i)
  {
    student_list[i].printSelf();
    cout << endl;
  }
  
  // 5. Print the letter grade of each student (in the list)
  cout << "Student grade list:\n"
       << "-------------------\n";
  for(int i = 0; i < 5; ++i)
  {
    cout << "Student " << i << ":" 
         << student_list[i].getLetterGrade() << endl;
  }
  
  return 0;
}
