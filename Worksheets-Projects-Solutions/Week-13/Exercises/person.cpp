#include <iostream>
#include <string>

using namespace std;

class Person
{
  public:
    string name;
    int height;
    Person(string n, int h) : name(n), height(h) 
    { }
    void printSelf()
    {
      cout << "Name: " << name << "\nHeight: " << height << endl;
    }
};

int main()
{
  Person * pptr;
  pptr = new Person("Jay", 5); // dynamically create a Person via pptr
  
  Person p1("Jill", 7);
  
  if( pptr != NULL ) // alternatively, if(pptr)
  {
    // pptr "points" to a Person object, meaning we need to dereference pptr first
    
    cout << (*pptr).name << endl;   // Jay; dot operator takes precedence so you need parentheses
    cout << pptr->name << endl;     // Jay; easier version of the previous line
    
    cout << (*pptr).height << endl; // 5; same issue as above
    cout << pptr->height << endl;   // 5; same note
    
    // p1 is a Person object, which means we do not need to do any dereference work first
    cout << p1.name << endl;       // Jill; dot operator is used here
    cout << p1.height << endl;     // 7; same note as before
    
    // function call example
    pptr->printSelf();
    p1.printSelf();
    
    // remember to do memory management
    delete pptr;
  }
  else
  {
    cout << "ERROR: Could not allocate enough memory to create a Person." << endl;
  }
  
  return 0;
}
