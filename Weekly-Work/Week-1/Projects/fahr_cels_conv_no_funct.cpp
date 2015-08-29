/*
  Name: Joe Greene
  Program: Temperature Converter (Celsius/Fahrenheit)
  Purpose: To convert temperatures given by the user (either Celsius or Fahrenheit). 
           The program prints both the Celsius and Fahrenheit in the end.
  Notes: 
    - This program uses basic console IO (no error-checking)
    - This program serves as a teaching tool
    - No custom functions are used in this version.
    - For more explanation on cin.ignore(1000, '\n'), check out this 
      link: http://www.cplusplus.com/reference/istream/istream/ignore/
*/

#include <iostream>
#include <string>

using namespace std; // lets us avoid typing "std::cout" and "std::cin"

int main()
{
  double temp_given = 0, conv_temp = 0;

  string temp_type = "";

  cout << "Is your temperature in Celsius or Fahrenheit? ";
  getline(cin, temp_type);

  cout << "Enter in your temperature: ";
  cin >> temp_given;

  cin.ignore(1000, '\n'); // ignores 1000 characters (if they exist) up until a new line

  if("Celsius" == temp_type)
  {
    cout << "Celsius: " << temp_given << endl; // convert Celsius to Fahrenheit
    conv_temp = temp_given * 1.8 + 32;
    cout << "Fahrenheit: " << conv_temp << endl;
  }
  else  // assume Fahrenheit to Celsius conversion
  {
    conv_temp = (temp_given - 32) / 1.8;  // convert Fahrenheit to Celsius
    cout << "Celsius: " << conv_temp << endl;
    cout << "Fahrenheit: " << temp_given << endl;
  }

  // custom "system("pause");" code
  cout << "Press ENTER to exit this program.";
  cin.ignore(1000, '\n');   // same as earlier

  return 0;
}