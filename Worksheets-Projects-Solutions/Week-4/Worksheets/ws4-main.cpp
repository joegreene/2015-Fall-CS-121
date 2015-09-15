#include <iostream>

using std::cout;

// function prototypes
int    getSum(int a, int b);          // two variables passed by value
double squareOf(double x);            // one variable passed by value
void   setDoubleToFive(double& var);  // one variable passed by reference
int    factorialOf(int n);            // one variable passed by value
char   getUpperCaseLetter(char& ch);  // one variable passed by reference

int main() 
{
  int int_one = 5, int_two = 8, int_three = 99;
  double dbl_one = 12.0, dbl_two = 3.0, dbl_three = -4.0;
  char char_one = 'b', char_two = 'y';
  
  // first set of function calls
  int_three = getSum(int_one, int_two);
  dbl_two = squareOf(dbl_one);
  setDoubleToFive(dbl_three);
  
  // first set of outputs
  cout << int_one << " " << int_two << " " << int_three << "\n";
  cout << dbl_one << " " << dbl_two << " " << dbl_three << "\n";
  cout << char_one << " " << char_two << "\n";
  
  // second set of function calls
  int_one = factorialOf(5);
  char_two = getUpperCaseLetter(char_one);
  
  // second set of outputs
  cout << int_one << " " << int_two << " " << int_three << "\n";
  cout << dbl_one << " " << dbl_two << " " << dbl_three << "\n";
  cout << char_one << " " << char_two << "\n";
  
  return 0;
}

int getSum(int a, int b)
{
  return (a+b);
}


double squareOf(double x)
{
  return (x*x);
}

void setDoubleToFive(double& var)
{
  var = 5 + 5 - 5;
}


int factorialOf(int n)
{
  int fact = 1;
  
  for(int i = n; i > 1; --i)
  {
    fact*=i;
  }
  
  return fact;
}

char getUpperCaseLetter(char& ch)
{
  if(ch > 90)  // if ch is not upper-case (upper is 65 - 90 and lower is 97 - 122)
  {
    ch -= ' ';
    return ch;
  }
  else
  {
    return (ch = 'A');
  }
}
