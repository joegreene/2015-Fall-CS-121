#include <iostream>
#include <string>

using namespace std;

class Person; // similar to prototyping functions
class Shirt;  // "                              "

const int MAX_NUM_SHIRTS = 5;

class Shirt
{
    friend Person; // allows Person to access Shirt's private variables
    string color;
    char size;
  public:
    Shirt(char s, string c) // initializes size and color
    {
      size = s;
      color = c;
    }
    
    void setSize(char s) { size = s; }
    void setColor(string c) { color = c; }
    
    void printSelf()
    {
      cout << "Shirt size: " << size 
           << "\nShirt color: " << color << endl;
    }
};

class Person
{
    string name;
    int shirt_count;                       // amount of shirts person owns
    Shirt * owned_shirts[MAX_NUM_SHIRTS];  // array of Shirt pointers
  public:
    Person(string n);
    Person(const Person& p);
    ~Person();
    
    void addShirt(char s, string c);
    void removeLastShirt();
    void editShirt(int ix, char s, string c);
    
    bool hasShirts();
    void printSelf();
};

Person::Person(string n) : name(n), shirt_count(0) 
{ }

Person::Person(const Person& p) : name(p.name), shirt_count(p.shirt_count)
{
  for(int ix = 0; ix < shirt_count; ++ix)
  {
    owned_shirts[ix] = new Shirt(p.owned_shirts[ix]->size,
                                 p.owned_shirts[ix]->color);
  }
}

Person::~Person()
{
  for(int ix = 0; ix < shirt_count; ++ix) // delete all allocated shirts
  {
    delete owned_shirts[ix];
  }
}

void Person::addShirt(char s, string c)
{
  if(shirt_count < MAX_NUM_SHIRTS)  // if we haven't hit the max shirt count
  {
    owned_shirts[shirt_count] = new Shirt(s, c);
    
    if( shirt_count ) // if we created the Shirt
    {
      shirt_count++;
    }
    else // memory did not allocate
    {
      cout << "ERROR: Could not allocate memory to make a new Shirt!";
    }
  }
}

void Person::removeLastShirt()
{
  if( hasShirts() )
  {
    delete owned_shirts[shirt_count-1];
    owned_shirts[shirt_count-1] = NULL; // to be safe we do this
    shirt_count--;
  }
}

void Person::editShirt(int ix, char s, string c)
{
  if(ix > 0 && ix < shirt_count)
  {
    owned_shirts[ix]->setSize(s);
    owned_shirts[ix]->setColor(c);
  }
  else
  {
    cout << "Invalid index specified (out of bounds)." << endl;
  }
}

bool Person::hasShirts()
{
  return (shirt_count != 0);
}
void Person::printSelf()
{
  cout << "Name: " << name
       << "\nShirt count: " << shirt_count
       << "\nShirts list: ";
  for(int ix = 0; ix < shirt_count; ++ix)
  {
    cout << "Shirt: " << ix << endl;
    owned_shirts[ix]->printSelf();
  }
}

int main()
{
  // type whatever you want here
  
  return 0;
}
