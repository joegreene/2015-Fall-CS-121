/*
  Name: Joe Greene
  Program: Temperature Converter (Celsius/Fahrenheit)
  Purpose: To convert temperatures given by the user (either Celsius or Fahrenheit). 
           The program prints both the Celsius and Fahrenheit in the end.
  Notes: 
    - This program uses basic console IO (no error-checking)
    - This program serves as a teaching tool
    - Custom functions are used in this program.
    - For more explanation on cin.ignore(1000, '\n'), check out this 
      link: http://www.cplusplus.com/reference/istream/istream/ignore/
*/

#include <iostream>
#include <string>

using namespace std; // lets us avoid typing "std::cout" and "std::cin"

// Function prototypes
double fahr_to_cels(double fahr);             // function to convert Fahrenheit to Celsius; returns Celsius (double)
double cels_to_fahr(double cels);             // function to convert Celsius to Fahrenheit; returns Fahrenheit (double)
void   print_temp(double cels, double fahr);  // function to print temperatures; returns nothing (void)
void   pause_program();                       // custom "pause" function; returns nothing (void)

int main()
{
  double temp_given = 0,
  conv_temp = 0;

  string temp_type = "";

  cout << "Is your temperature in Celsius or Fahrenheit? ";
  getline(cin, temp_type);

  cout << "Enter in your temperature: ";
  cin >> temp_given;

  cin.ignore(1000, '\n'); // ignores 1000 characters (if they exist) up until a new line

  if("Celsius" == temp_type)
  {
    conv_temp = cels_to_fahr(temp_given);
    print_temp(temp_given, conv_temp);
  }
  else
  {
    conv_temp = fahr_to_cels(temp_given);
    print_temp(conv_temp, temp_given);
  }
  
  pause_program();

  return 0;
}

// function to convert Fahrenheit to Celsius; returns Celsius (double)
double fahr_to_cels(double fahr)
{
  return (fahr - 32) / 1.8;
}

// function to convert Celsius to Fahrenheit; returns Fahrenheit (double)
double cels_to_fahr(double cels)
{
  return (cels * 1.8) + 32;
}

// function to print temperature; returns nothing (void)
void print_temp(double cels, double fahr)
{
  cout << "Celsius: " << cels << endl << "Fahrenheit: " << fahr << endl;
}

// custom "system("pause");" code; returns nothing (void)
void pause_program()
{
  cout << "Press ENTER to exit this program.";
  cin.ignore(1000, '\n');
}