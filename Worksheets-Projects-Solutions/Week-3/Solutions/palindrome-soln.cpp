/*
** Name: Joe Greene
** Program: Palindrome Checker Program
** Purpose: To check if a given string is a palindrome.
**
** Notes: 
** - This program only tests the palindrome function (and is not a fully-fledged program).
**
** Known issues: None so far.
*/

// libraries
#include <iostream> 
#include <string>    // required for using strings
#include <cctype>    // required for "isalpha" call in palindrome function

// namespace uses
using std::cout;
using std::string;

// function prototype
void printPalindrome(string str);  // prints to console if string is a palindrome

/*
** Name: main
** Purpose: Acts as a driver for the palindrome function
** Return: 0 (error code, which '0' means no errors)
*/
int main() 
{
  // various tests for printPalindrome function
  printPalindrome("racecar");
  printPalindrome("A but tuba");
  printPalindrome("b");
  printPalindrome("palindrome");
  printPalindrome("Computer");
  printPalindrome("This is not a palindrome");
  printPalindrome("A toyota's a toyota");
  return 0;
}

/*
** Name: printPalindrome
** Purpose: To print whether or not a string is a palindrome (the function only prints)
** Return: Nothing. The function only prints a palindrome.
*/
void printPalindrome(string user_str) 
{
  if(user_str.length() == 1) 
  {
    cout << "\'" << user_str << "\' is a palindrome.\n";
  }
  else 
  {
    // we'll be doing nasty stuff to this string so let's make a backup
    string str = user_str;

    // these are used for the palindrome checking (later)
    char left_char;
    char right_char;

    // Two steps to format (or "scrub") string prior to checking if palindrome
    // 1. Remove all non-alphabetical letters from the string
    // 2. Set all characters to either upper or lower
    for(int i = 0; i < str.length(); ++i) 
    {
      if(!isalpha(str[i])) 
      {
        str.erase(i,1); // erase at 1 only 1 character (so "str.erase(i,2)" would erase at i and i+1)
      }
      else 
      {
        str[i] = tolower(str[i]);
      }
    }

    // Now, check if the variable is a palindrome (working inwards so we only have to go half-way)
    for(int i = 0; i < str.length()/2; ++i) 
    {
      // write out the index of each if looking at this doesn't make sense (it's working inwards)
      left_char = str[i];
      right_char = str[str.length() - 1 - i];
      
      if(left_char != right_char) 
      {
        cout << "\'" << user_str << "\' is not a palindrome.\n";
        return; // exit the function
      }
    }

    // if the for loop finished without printing "... not a palindrome", it is a palindrome
    cout << "\'" << user_str << "\' is a palindrome.\n";
  }
}
