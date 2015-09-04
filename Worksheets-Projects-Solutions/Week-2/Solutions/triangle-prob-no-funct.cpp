/*
** Name: Joe Greene
** Program: Triangle Checker Program
** Purpose: To calculate whether or not three given side lengths of a triangle form
**          an equilateral triangle, right triangle, or neither.
** Notes: 
** - This program acts more as a quick solution than anything else
** - This program does very little input validation
**
** Known issues: None so far.
*/

#include <iostream>
using std::cout;
using std::cin;

int main()
{
  // side lengths (I like to manually initialize variables just to be safe)
  int a = 0, b = 0, c = 0;
  char cont = 'y';  

  do
  {
    cout << "Please enter three side lengths (separated by spaces): ";
    cin  >> a >> b >> c;

    // doing this solely out of laziness of typing
    cout << "The side lengths provided ";
  
    if (a == b && b == c) //equilateral case
    {
      cout << "form an equilateral triangle.\n";
    }
    else if ( ((a*a) + (b*b)) == (c*c) )
    {
      cout << "form a right triangle.\n";
    }
    else
    {
      cout << "do not form an equilateral or a right triangle.\n";
    }

    cout << "Another triangle (y/n)?: ";
    cin  >> cont;
    
  }while('Y' == toupper(cont));
  
  return 0;
}
