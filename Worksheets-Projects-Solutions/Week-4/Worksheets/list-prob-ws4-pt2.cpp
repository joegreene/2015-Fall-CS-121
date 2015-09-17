#include <iostream>
using namespace std;
int main()
{
  int list[] = {0,1,1};
  int n = 7, x;
  
  cout << "INITIAL: \n[" << list[0] << " " << list[1]
       << " " << list[2] << "]\n\n";
       
  cout << "LOOP:\n";
  for(x = 3; x <= n; ++x)
  {
    static int y = x-1, z = x-2;
    
    list[x%3] = list[y%3] + list[z%3];
    y++;
    z++;
    
    cout << "[" << list[0] << " " << list[1]
         << " " << list[2] << "]\n";
  }
  
  x--; // doing this since the for loop shifted x up one
  
  cout << "Value when n=" << n << ": " << list[x%3] << "\n";
  
  return 0;
}