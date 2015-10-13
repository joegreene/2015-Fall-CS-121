/*
  File: cfvmain.cpp
  Notes:
  - Look at the backside of this page for the questions pertaining this work
*/
#include "cfloatvector.h"
int main()
{
  // 1. Create two CFloatVectors `first_list` and `second_list` with capacities 5 and 10.
  CFloatVector first_list(5);
  CFloatVector second_list(10);
  
  // 2. Push the values `1.0 1.0 2.0 3.0 5.0` to the back of `first_list` (in the order presented)
  
  first_list.push_back(1.0);
  first_list.push_back(1.0);
  first_list.push_back(2.0);
  first_list.push_back(3.0);
  first_list.push_back(5.0);
  
  // 3. Push the seven even numbers from 2 to 14 to the back of `second_list` (in increasing order)
  for(float i = 2.0; i <= 14.0; i+=2.0)
  {
    second_list.push_back(i);
  }
  
  // 4. Copy the contents of `second_list` to a new CFloatVector called `third_list`
  CFloatVector third_list(second_list);
  
  // 5. Push the value `2.718` to the back of `first_list`
  first_list.push_back(2.718);
  
  // 6. Print the contents of `first_list`, `second_list`, and `third_list`
  cout << "First list:\n";
  first_list.print_contents();
  cout << "Second list:\n";
  second_list.print_contents();
  cout << "Third list:\n";
  third_list.print_contents();
  
  // 7. Print the last element of each list
  cout << "first_list's last element: "    << first_list.at(third_list.size()-1)
       << "\nsecond_list's last element: " << second_list.at(third_list.size()-1)
       << "\nthird_list's last_element: "  << third_list.at(third_list.size()-1)
       << endl;
  
  // 8. Using the methods of CFloatVector, print if `first_list` is empty, what the size and max 
  //    capacity of `second_list` is, and if `third_list` is full
  cout << "First list is empty: "  << first_list.is_empty()
       << "\nSecond list's size: " << second_list.size()
       << "\nSecond list's capacity: " << second_list.max_size()
       << "\nThird list is full: " << (third_list.size() == third_list.max_size()) << endl;
  
  // 9. Clear `second_list` and `third_list`, and pop the back of `first_list` twice
  second_list.clear();
  third_list.clear();
  first_list.pop_back();
  first_list.pop_back();
  
  // 10. Print the contents of each list again
  cout << "First list:\n";
  first_list.print_contents();
  cout << "Second list:\n";
  second_list.print_contents();
  cout << "Third list:\n";
  third_list.print_contents();
  return 0;
}

/*
  Questions/Problems:
  1. Fill out cfloatvector.h and cfvmain.cpp if you have not yet.
  
  <CHECK ABOVE>
  
  2. In cfvmain.cpp, are any includes required? If so, which? Explain your answer.
  
  <CHECK ABOVE> and the reason for it is to actually use the class
  
  3. What methods, if any, would you consider useful to include with CFloatVector?
  
  Examples:
  - is_full(): see if list is full
  - front(): get first element
  - back(): get last element
  - append(CFloatVector): append (i.e. add to end) another CFloatVector to another (if capable)
  
  4. Give an example of how implementing the default constructor may look like.
  
  CFloatVector::CFloatVector() : CAPACITY(100) // set default capacity to 100 or some arbitrary value
  {
    count = 0;
  }
  
  
  
  
*/
