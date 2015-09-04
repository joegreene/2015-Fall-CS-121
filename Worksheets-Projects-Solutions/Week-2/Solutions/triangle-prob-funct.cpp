/*
** Name: Joe Greene
** Program: Triangle Checker Program
** Purpose: To calculate whether or not three given side lengths of a triangle form
**          an equilateral triangle, right triangle, or neither.
** Notes: 
** - This program serves as an alternative to the first solution
** - This program does very little input validation (only ranged-based for the menu)
**
** Known issues: None so far.
*/
#include <iostream>

using std::cout;
using std::cin;

// function prototypes (lets the compiler know you're defining the functions elsewhere)
void printTriangleType(int a, int b, int c);
bool doRestart();

int main()
{
  // side lengths (I like to manually initialize variables just to be safe)
  int a = 0, b = 0, c = 0;

  do
  {
    // This prompt/cin part can be a function as well. An example is shown in 
    // the triangle-prob-funct-improved.cpp solution
    cout << "Please enter three side lengths (separated by spaces): ";
    cin  >> a >> b >> c;

    printTriangleType(a, b, c);
    
  }while( doRestart() );
  
  return 0;
}

/*
**  printTriangleType:
**    Determines (via side lengths) the type of triangle they represent
**    and prints the result to standard output.
*/
void printTriangleType(int a, int b, int c)
{
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
}

/*
**  doRestart:
**    Asks the user if they want to restart (and returns a boolean dictating 
**    their choice).
*/
bool doRestart()
{
  char cont = 'n';
  cout << "Another triangle (y/n)?: ";
  cin  >> cont;
  
  return (toupper(cont) == 'Y');
}
