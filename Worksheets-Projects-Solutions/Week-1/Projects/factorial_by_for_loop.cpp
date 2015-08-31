/*
  Name: Joe Greene
  Program: Print Factorial
  Purpose: To print the factorial of a positive integer
  Notes: 
    - This program uses basic console IO (minor error-checking)
    - This program serves as a teaching tool
    - I wouldn't suggest trying n-values over 69, unless you want to see integer 
      overflow occur.
    - The program assumes the user inputs integers only
    - For more explanation on cin.ignore(1000, '\n'), check out this 
      link: http://www.cplusplus.com/reference/istream/istream/ignore/
*/

#include <iostream>
#include <string>

using namespace std; // lets us avoid typing "std::cout" and "std::cin"

int main()
{
  int n = 0;
  
  cout << "Enter an integer to find its factorial: ";
  cin >> n;
  
  if(0 <= n) // if the n-value is greater than or equal to zero, compute the factorial
  {
    int fact = 1; //the actual computed factorial value (this also covers cases n=1 and n=0)
    
    // compute the factorial
    for(int i = n; i > 1; --i)
    {
      fact *= i;
    }
    
    cout << n << "! = " << fact << endl;
  }
  else // n-value is negative (error in our program)
  {
    cout << "n-value is negative! Cannot compute factorial.\n";
  }

  // custom "system("pause");" code
  cout << "Press ENTER to exit this program.";
  cin.ignore(1000, '\n');   // ignores 1000 characters (if they exist) up until a new line

  return 0;
}