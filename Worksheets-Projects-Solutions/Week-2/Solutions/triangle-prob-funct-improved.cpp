/*
** Name: Joe Greene
** Program: Triangle Checker Program
** Purpose: To calculate whether or not three given side lengths of a triangle form
**          an equilateral triangle, right triangle, or neither.
** Notes: 
** - This program is designed to show how functions provide easy modification, 
**   allows major improvement, and promotes reuse of code
** - This program does very little input validation (only ranged-based for the menu)
**
** Known issues: None so far.
*/
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// function prototypes (in chronological order)
void displayMenu();
int  getMenuInput();
void handleMenuInput(int choice, bool& cont); // '&' part is explained below
void getSideLengths(int& a, int& b, int& c);  
void printTriangleType(int a, int b, int c);

/*
**  main:
**    Driver of the program (entry point for the operating sytem when it runs
**    this executable file)
*/
int main()
{
  // side lengths, input variable (for menu), and flag for program continuation
  int input = -1;
  bool cont = true;

  // you can treat the below like the "conversation loop" mentioned in lecture 9/3
  do 
  {
    displayMenu();                // Prompt (this was shifted inside the loop)
    input = getMenuInput();       // Also a part of the prompt
    handleMenuInput(input, cont); // Respond (including update)
  }while( cont );                 // End check
  
  return 0;
}

/*  displayMenu:
**    Displays a neat menu for the user
*/
void displayMenu()
{
  cout << "Triangle Checker Program:\n"
       << "-------------------------\n"
       << "1. Identify triangle via side lengths:\n"
       << "2. Quit\n"
       << "-------------------------\n"
       << "Please enter your choice: ";
}

/*
** getMenuInput:
**   Retrieves menu input
*/
int getMenuInput()
{
  // I know this function isn't doing much, but leaving it as a function 
  // allows for any possible improvement later on (and makes main look cleaner)
  int input = -1;
  cin >> input;

  return input;
}

/*
**  By-value vs. By-reference:
**  --------------------------
**  Recap on arguments vs parameters:
**    - Arguments: variables/values used in a function call
**    - Parameters: what the function sees and uses in the function body
**    - e.g. f(x) = x^2 and f(2.0) = 4.0; x is a parameter and 2.0 is an argument
**
**  Concise explanation (if this isn't enough best to check online):
**    - By-value: No '&', arguments are unaffected (copied)
**    - By-reference: Use '&', arguments are affected if manipulated (referred to)
**      - In this, the variable is known as being aliased
*/

/*
**  handleMenuInput:
**    Handles/filters menu input and returns to the caller whether or not the 
**    user wishes to recontinue the program. The recontinue/quit request is sent 
**    back to the caller via "bool& cont".
*/
void handleMenuInput(int input, bool& cont)
{
  // another cool concept: enumeration allows you to create a list of integers
  enum { IDENTIFY = 1, QUIT };
  
  // variables for side lengths
  int a = 0, b = 0, c = 0;

  switch(input)
  {
    case IDENTIFY:
      getSideLengths(a, b, c);
      printTriangleType(a, b, c);
      break;
    case QUIT:
      cont = false;
      break;
    default: // acts like an "else" in an if/else chain
      cout << "Invalid input. Please provide an input between "
           << IDENTIFY << " and " << QUIT << endl;
  }
}

/*
**  getSideLengths:
**    Returns (to the caller) three integer side lengths
*/
void getSideLengths(int& a, int& b, int& c)
{
  cout << "\nPlease enter three side lengths (separated by spaces): ";
  cin  >> a >> b >> c;
  // becomes easy to include input validation here, if desired
}

/*
**  printTriangleType:
**    Determines (via side lengths) the type of triangle they represent
**    and prints the result to standard output.
*/
void printTriangleType(int a, int b, int c)
{
  cout << "The side lengths provided ";
  
  if (a == b && b == c) //equilateral case
  {
    cout << "form an equilateral triangle.\n\n";
  }
  else if ( ((a*a) + (b*b)) == (c*c) )
  {
    cout << "form a right triangle.\n\n";
  }
  else
  {
    cout << "do not form an equilateral or a right triangle.\n\n";
  }
}
