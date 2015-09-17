/*
   Programmer: Joe Greene
   Program: Factorial Memoization Program
   Purpose: To serve as an example of memoizing a factorial function and to show 
            the difference between a non-memoized and memoized function.
            
   Notes:
   - To compile this program you need a C++11-compatible compiler (Visual Studio 2012 
     and up will work, possibly 2010).
     
   - As it is currently set up now, this program computes 60! (2 * NUM_ITERATIONS) times.
     The first loop does computation every single iteration, whereas the second loop uses 
     memoization.
  
   - You are not expected to know all the "chrono" and time stuff.

   - Play around with (super high) values for NUM_ITERATIONS.

   - Unless you replace all the "int" with "unsigned long long", I wouldn't bother 
     printing out the factorials. There is extreme overflow with this program.
*/

#include <chrono>   // for doing the time stuff
#include <iostream>

using namespace std;

// function prototypes
int getFactorial(int n); // for user (easier to remember/type this than memoFact)
int memoFact(int n);     // for programmer and efficiency-boost (returns factorial)
int computeFact(int n);  // for actually computing a factorial

int main()
{
  // NOTE: Max value of an unsigned long long is 2^64 - 1, whereas the 
  //       unsigned int is 2^32 - 1 (so use big values here!)
  const unsigned long long NUM_ITERATIONS = 270000000;
  
  // starting clock
  auto start_first = chrono::high_resolution_clock::now();
  
  cout << "NUM_ITERATIONS: " << NUM_ITERATIONS << endl;
  
  cout << "Running first loop (no memo)...\n";
  for(int i = 0; i < NUM_ITERATIONS; ++i)
  {
    computeFact(60);
  }
  
  // end clock (after first computation loop)
  auto end_first = chrono::high_resolution_clock::now();
  
  // calculating elapsed time
  int microseconds_first = chrono::duration_cast<chrono::microseconds>(end_first - start_first).count();
  double seconds_first = microseconds_first / 1E6;
  cout << "Time elapsed for first loop: " << seconds_first << " seconds\n\n";
  
  // second starting clock
  auto start_second = chrono::high_resolution_clock::now();
  
  cout << "Running second loop (memo)...\n";
  for(int i = 0; i < NUM_ITERATIONS; ++i)
  {
    getFactorial(60);
  }
  
  // end clock (after second computation loop)
  auto end_second = chrono::high_resolution_clock::now();
  
  // calculating elapsed time
  int microseconds_second = chrono::duration_cast<chrono::microseconds>(end_second - start_second).count();
  double seconds_second = microseconds_second / 1E6;
  cout << "Time elapsed for second loop: " << seconds_second << " seconds\n";
  
  return 0;
}

int getFactorial(int n)
{
  if(n == 0 || n == 1)
  {
    return 1;
  }
  else                       // READ FOOTNOTE #1:
  {
    int fact = memoFact(n);  // get n! (how fast this works depends on if n! is saved in memoFact)
    return fact;
  }
}

int memoFact(int n)
{
  const int MAX_STORAGE = 3;         // READ FOOTNOTE #2

  static int n_list[MAX_STORAGE];    // holds n values  (parallel to fact_list)
  static int fact_list[MAX_STORAGE]; // holds n! values ("                   ")

  int return_fact;                   // factorial value to be returned (i.e. return_fact = n!)

  static int real_count = 0,         // actual number of stored factorials (can be < MAX_STORAGE)
             next_index = 0;         // holds index to place next-computed factorials in later function calls

  bool found_fact = false;           // for checking if n! was found in the storage lists

  for(int i = 0; i < real_count; ++i)  // check list for 
  {
    if(n == n_list[i])                 // if n value was already computed
    {
      return_fact = fact_list[i];      // get corresponding n!
      found_fact = true;               // mark flag to true
      break;                           // no need to check rest of list so escape the for-loop
    }
  }

  if(!found_fact)                          // if we unfortunately did not find the factorial in the list
  {
    int new_index = next_index;            // new_index is the index we plan to store n and n! at
    next_index++;                          // move next_index forward (to get to next oldest spot) 
    next_index %= MAX_STORAGE;             // READ FOOTNOTE #3

    if(real_count < MAX_STORAGE)           // if the list isn't filled yet
    {
      real_count++;
    }
    
    return_fact = computeFact(n);          // get n!
    fact_list[new_index] = return_fact;    // store n! into the factorial list
    n_list[new_index] = n;                 // store corresponding n value in the n-value list
  }

  return return_fact;  // return the factorial the user requested (from getFactorial)
}

int computeFact(int n)
{
  int fact = 1;
  
  for(int i = n; i > 1; --i)
  {
    fact*=i;
  }

  return fact;
}