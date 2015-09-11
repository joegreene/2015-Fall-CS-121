/*
** Name: Joe Greene
** Program: Palindrome Checker Program
** Purpose: To check if a given string is a palindrome.
**
** Notes: 
** - This program only tests the palindrome function (and is not a fully-fledged program).
** - I made functions for leap year and month end as I figured the code may be used elsewhere in 
**   the program (as the validate function is a part of a bigger program, as mentioned in the prompt)
** - The output is rather large, so you might want to either use ideone.com or expand the terminal 
**   window (half the screen or something alike). There is also a output file in the repository.
**
** Known issues: None so far.
*/

// libraries
#include <iostream> 

// namespace uses
using std::cout;

// function prototype
bool verifyDateInput(int mm, int dd, int yyyy); // returns true/false if date given is valid
bool isLeapYear(int yyyy);                      // returns true/false if year is a leap year
int getMonthEnd(int mm);                        // returns the end day of the month

/*
** Name: main
** Purpose: Acts as a driver for the validate week function
** Return: 0 (error code, which '0' means no errors)
*/
int main() 
{
  // various tests for printPalindrome function (format: mm dd yyyy)
  
  cout << "DISCLAIMER: Empty output means no errors\n";
  
  cout << "\nTest 1: \n";
  verifyDateInput(11, 1, 1970);  // valid date
  cout << "\nTest 2: \n";
  verifyDateInput(2, 29, 1900);  // invalid year
  cout << "\nTest 3: \n"; 
  verifyDateInput(2, 29, 2100);  // invalid day (non leap year)
  cout << "\nTest 4: \n";
  verifyDateInput(12, -1, 1200); // dd and yyyy wrong
  cout << "\nTest 5: \n";
  verifyDateInput(-1, 31, 2096); // mm wrong
  cout << "\nTest 6: \n";
  verifyDateInput(13, 5, -1440); // mm and yyyy wrong
  cout << "\nTest 7: \n";
  verifyDateInput(9001, 9002, 1999); // mm and dd wrong
  cout << "\nTest 8: \n";
  verifyDateInput(-49, -50, 1969);   // mm, dd, and yyyy wrong
  cout << "\nTest 9: \n";
  verifyDateInput(2, 29, 2400);  // valid date (leap year)
  cout << "\n";
  
  return 0;
}


/* 
** Function Name: verifyDateInput
** Purpose: To verify the date from the user is valid (for the program)
** Parameters:
**   int   mm     [IN-PARAM]
**   int   dd     [IN-PARAM]
**   int   yyyy   [IN-PARAM]
** 
** Notes: The order of operation is:
** - Check year
** - Check months
**   - First if valid month (and inside of that if valid day)
**   - Second if 31-month and day in valid range
**   - Third if 30-month and day in valid range
**   - Lastly for February and if valid day range (leap year and not leap year cases)
** 
** Return: Boolean value determining whether or not the date given is invalid
*/
bool verifyDateInput(int mm, int dd, int yyyy) 
{
  const int LOWER_YEAR_BOUND = 1970;            // easy to change if we need to update the function
  
  bool validity = true,                         // for validity of date (returned value)
       day_between_31 = (1 <= dd && dd <= 31),  // each identifier implies between 01 and XX
       day_between_30 = (1 <= dd && dd <= 30),
       day_between_28 = (1 <= dd && dd <= 28);
  
  // returns -1 if given invalid month
  int month_end = getMonthEnd(mm);
  
  // check for valid year
  if ( yyyy < LOWER_YEAR_BOUND ) 
  {
    cout << "Invalid year given (must be between 1812 and 2012).\n";
    validity = false;
  }
  
  // if getMonthEnd returned invalid-month error code
  if ( month_end == -1 ) 
  {
    cout << "Invalid month given (must be between 01 - 12).\n";
    
    if ( !day_between_31 ) 
    {
      cout << "Invalid day given for any month (out of range).\n";
    }
    validity = false;
  }
  else if ( month_end == 31 && !day_between_31 ) 
  {
    cout << "Invalid day given for given month (must be between 01 - 31).\n";
    validity = false;
  }
  else if ( month_end == 30 && !day_between_30 ) 
  {
    cout << "Invalid day given for given month (must be between 01 - 30).\n";
    validity = false;
  }
  else 
  {
    if ( dd == 29 && !isLeapYear(yyyy) ) 
    {
      cout << "Invalid day given for given month/year (not a leap year).\n";
      validity = false;
    }
    else if (!day_between_28) 
    {
      cout << "Invalid day given for given month (must be between 01 - 28).\n";
      validity = false;
    } 
  }
  return validity;
}

/* 
** Function Name: isLeapYear
** Purpose: To see if a supplied year is a leap year
** Parameters:
**   int   yyyy   [IN-PARAM]
** 
** Note: In order for a year to be a leap year, it must abide to the following:
** - If the year is a century year (i.e. divisible by 100), it must be divisible by 400.
** - If the year is not a century year, it must be divisible by 4
**
** Return: Boolean value determining whether or not the year given is a leap year
*/
bool isLeapYear(int yyyy) 
{
  bool century_leap = (yyyy % 400 == 0),
       typical_leap = (yyyy % 4 == 0 && yyyy % 100 != 0);
  
  return (century_leap || typical_leap);
}

/* 
** Function Name: getMonthEnd
** Purpose: Returns the numerical value of the last day of a supplied month
** Parameters:
**   int   mm   [IN-PARAM]
** 
** Return: Integer value representing the last day of a supplied month (-1 for invalid month)
*/
int getMonthEnd(int mm) 
{
  // treat this is a list of integers
  enum {JAN = 1, FEB, MAR, APR, MAY, JUN, JULY, AUG, SEPT, OCT, NOV, DEC};
  
  // variable used as return value (28, 30, 31, or invalid month (-1))
  int month_end = -1;
  
  if (mm == JAN || mm == MAR || mm == MAY || mm == JULY || mm == AUG || mm == OCT || mm == DEC) 
  {
    month_end = 31;
  }
  else if (mm == APR || mm == JUN || mm == SEPT || mm == NOV) 
  {
    month_end = 30;
  }
  else if (mm == FEB) 
  {
    month_end = 28; // going off of most frequent end day for February
  }
  else 
  { 
    month_end = -1; // invalid month given
  }
  
  return month_end;
}
