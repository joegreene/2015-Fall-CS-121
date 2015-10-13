/*
  File: cfloatvector.h
  Purpose: Holds a class representing a custom float vector, consisting of a minimal method list.
  Notes:
  - You must fill in any blanks in the below code
  - The default constructor and assignment operator are never implemented. This is to prevent them 
    from ever being used by somebody using this class.
  - Due to language limitations (and, for now, avoiding pointers), the maximum size for an array 
    (regardless of requested capacity) is 1000 (or whatever ARRAY_SIZE is set to)
*/

#include <iostream>
using namespace std;
const int ARRAY_SIZE = 1000;  // for float array in class

class CFloatVector
{
    // member variables
    const int CAPACITY;     // maximum size our array can be (this is initialized below)
    int count;              // "true" amount of values in array
    float arr[ARRAY_SIZE];  // the float array (this program assumes less than ARRAY_SIZE elements)
    
  public:
    // constructors & destructor
    CFloatVector(int c);                   // overloaded constructor
    CFloatVector(const CFloatVector& fv);  // copy constructor; partial TO-DO
    ~CFloatVector();                       // destructor (for jokes mainly)
    
    // getters
    int size();                            // returns current amount of elements in list; TO-DO
    bool is_empty();                       // returns if any elements are in the list; TO-DO
    float& at(int index);                  // returns actual element at index (if valid); TO-DO
                                           // returns the maximum size of list (set by user); TO-DO
        
    // miscellaneous
    void pop_back();                       // clear last item in the list
    void push_back(float val);             // add item to back of the list; TO-DO
    void clear();                          // clear the vector; TO-DO
                                           // print contents of array; TO-DO
  
  private:
    // "disabled" methods 
    // - The below methods are made default in a class and this is a way to prevent their creation
    CFloatVector();                                   // default constructor
    CFloatVector& operator= (const CFloatVector& x);  // assignment operator
};

/*
          CONSTRUCTORS & DESTRUCTOR
*/

// overloaded constructor
CFloatVector::CFloatVector(int c) : CAPACITY(c)
{
  
}

// copy constructor; partial TO-DO
CFloatVector::CFloatVector(const CFloatVector& fv) : CAPACITY(fv.CAPACITY)
{
  for(count = 0; count < fv.count; ++count)
  {
    
  }
}



// destructor (for jokes mainly)
CFloatVector::~CFloatVector()
{
  cout << "Good-byte cruel world!\n";
}

/*
          END OF CONSTRUCTORS & DESTRUCTOR
*/
/*
          GETTER METHODS
*/
// returns current amount of elements in list; TO-DO




// returns if any elements in list; TO-DO
bool CFloatVector::is_empty()
{
  
}

// returns value at index (if valid); TO-DO
float& CFloatVector::at(int index)
{
  if(                           )
  {
    
  }
  else // raise error
  {
    cout << "ERROR: Invalid index (must be between 0 and count). Returning random variable.\n";
    float var = 0;  // some bad value (use a temp variable since we're returning by-reference)
    return var;     // this gives a warning but should be fine
  }
}

// returns the maximum size of list (set by user); TO-DO






/*
          END OF GETTER METHODS
*/
/*
          MISCELLANEOUS METHODS
*/

// clear last item in the list
void CFloatVector::pop_back()
{
  if(!is_empty())
  {
    count--; // just decrement count
  }
  else
  {
    cout << "ERROR: The CFloatVector is empty.\n";
  }
}



// add item to back of list; TO-DO
void CFloatVector::push_back(float val)
{
  
  
  
  
  
  
  
  
  
}

// clear the vector; TO-DO
void CFloatVector::clear()
{
  
}

// print contents of array; TO-DO











/*
          END OF MISCELLANEOUS METHODS
*/
