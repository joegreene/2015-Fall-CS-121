#include <iostream>

using namespace std;

class Chicken
{
    int num_eggs;
    int num_feathers;
  public:
    Chicken(int e, int f) : num_eggs(e), num_feathers(f) 
    { }
    int getNumEggs() { return num_eggs; }
    int getNumFeathers() { return num_feathers; }
    
    void setNumEggs(int e) { num_eggs = e; }
    void setNumFeathers(int f) { num_feathers = f; }
    
    void printSelf()
    {
      cout << "Eggs: " << num_eggs << "\nFeathers: " << num_feathers << endl;
    }
};

int main()
{
  Chicken * cptr;
  cptr = new Chicken (3, 5); // dynamically create a Chicken via cptr
  
  if( cptr != NULL ) // alternatively, if(cptr)
  {
    // cptr "points" to a Chicken object, meaning we need to dereference cptr first
    
    // 1. Print num_eggs
    cout << cptr->getNumEggs() << endl;
    // 2. Print num_feathers
    cout << cptr->getNumFeathers() << endl;
    // 3. Set num_eggs to 24000
    cptr->setNumEggs(24000);
    // 4. Set num_feathers to 123454321
    cptr->setNumFeathers(123454321);
    // 5. Call printSelf
    cptr->printSelf();
    
    // remember to do memory management afterwards
    delete cptr;
  }
  else
  {
    cout << "ERROR: Could not allocate enough memory to create a Person." << endl;
  }
  
  return 0;
}
