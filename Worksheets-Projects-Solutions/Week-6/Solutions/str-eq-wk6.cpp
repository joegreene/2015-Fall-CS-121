/*
  Name: Joe Greene
  Project: Case-Insensitive String Compare
  Purpose: To be able to perform case-insensitive string equality comparison
  Notes: None.
*/
// libraries
#include <string>
#include <iostream>
#include <cctype>

// namespaces used
using namespace std;

// function Prototypes
string upperCaseIt(string s);
bool sameString(string s1, string s2);

// definition of main
int main()
{
  string name1, name2;
  bool equal_names = false; // default value is to be a pessimist
  
  cout << "Please enter the first name for comparison: ";
  getline(cin, name1);
  
  cout << "Please enter the second name for comparison: ";
  getline(cin, name2);
  
  equal_names = sameString(name1, name2);
  
  cout << "Names \"" << name1 << "\" and \"" << name2 << "\" are "
       << ( (equal_names == true) ? " the same." : " different." ) 
       << endl;
  
  // The above "(...) ? ... : ..." (line 34) is called the conditional (ternary) operator. 
  // Think of it as a condensed if/else.
  
  return 0;
}

// definition of upperCaseIt
string upperCaseIt(string s)
{
  // s was sent by-value so no need to make a new string object
  for(int i = 0; i < s.length(); ++i)
  {
    s[i] = toupper(s[i]);
  }
  return s;
}

// definition of sameString
bool sameString(string s1, string s2)
{
  // both s1 and s2 are passed by-value so we're free to manipulate them
  s1 = upperCaseIt(s1);
  s2 = upperCaseIt(s2);
  
  return (s1 == s2);
}