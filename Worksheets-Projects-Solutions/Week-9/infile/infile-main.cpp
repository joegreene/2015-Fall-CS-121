/*
  Program:    ifstream-example
  Programmer: Everyone who was at the SI session on 10/20/2015.
  Notes:
  - ifstream works just like cin, except you have to see if you've opened your file first
    before actually working with it.
    
  - This program's purpose is to show briefly how to work with ifstream.
  
  - This program fills up an array of integers until it is filled up or there 
    are no more elements to grab from the file provided.
  
  - I know line 35 looks nasty (the '>>' portion), but really it's the best solution 
    (or at least the best I know of in C++). 
    - e.g. "infile.eof()" means "infile has reached end-of-file", which sounds 
      like an amazing way to check if you've grabbed everything. Unfortunately, there is an issue 
      with how it works. Check the below link for an example of why:  
  http://stackoverflow.com/questions/21647/reading-from-text-file-until-eof-repeats-last-line
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
  // Set up a maximum size (capacity) for our integer list
  const int MAX_SIZE = 50;
  
  // Our integer list
  int int_list[MAX_SIZE];
  
  // Name of the file we wish to read from
  string fname = "data-file.txt";
  
  // The number of elements we will grab from the input file
  int count = 0;
  
  ifstream infile;
  
  // Because ifstream's 'open' method doesn't know how to read std::string, we give it 
  // a c-string instead
  infile.open(fname.c_str());
  
  // If the file was opened successfully (alternatives are infile.is_open() or infile.good()
  if(infile)
  {
    cout << "File opened\n";
    
    // Two conditions here to check (both must be true to continue reading the file):
    // 1. While we haven't completely filled the array (count < MAX_SIZE)
    //
    // 2. While we can still grab integers from the file 
    //   i. In the same line this also sets up the value of int_list[count]
    while( (count < MAX_SIZE) && (infile >> int_list[count]) )
    {
      cout << int_list[count] << endl;
      ++count;
    }
    
    // Always close your files after you're done or else the file might become corrupted or 
    // your program will "hang"
    infile.close();
  }
  else
  {
    // file was not opened or failed to open (due to mistyped file name, insufficient read 
    // privileges, etc.)
    cout << "ERROR: File was not opened\n";
  }
  
  return 0;
}
