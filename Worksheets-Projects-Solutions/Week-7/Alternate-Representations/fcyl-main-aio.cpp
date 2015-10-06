/*
  This file is an example of including everything in one .cpp file.
  
  AIO == all-in-one
*/

#include <iostream>

using namespace std;

// required for volume and area methods
const double PI = 3.141592;

class FCylinder
{
  private:
    // member variables
    double radius, height;              // doubles for radius & height

  public:
    FCylinder();                        // default constructor
    FCylinder(double r, double h);      // overloaded constructor
    FCylinder(const FCylinder& fc);     // copy constructor; optional as C++
                                        // defines this automatically (I added
                                        // this solely to show how it looks)
    ~FCylinder();                       // deconstructor

    // getter Methods
    double getRadius();                 // return radius
    double getHeight();                 // return height (TO-DO)
    
    // setter Methods
    void setRadius(double r);           //set radius (with bounds-checking)
    void setHeight(double h);           //set height (with bounds-checking)
    
    // misc. Methods
    double computeSurfaceArea();        // returns surface area of FCylinder

    double computeVolume();             // returns volume of FCylinder

    void printSelf();                   // print member variables of FCylinder
};

/*
  Below is copy-paste of the FCylinder.cpp source file from the Solutions folder.
*/

// default constructor
FCylinder::FCylinder()
{
  // default initialization
  radius = height = 1;
}

// overloaded constructor
FCylinder::FCylinder(double r, double h)
{
  // first assign default value
  radius = height = 1;

  // afterwards, attempt to assign the values of r, h to radius, height
  setRadius(r);
  setHeight(h);

  // NOTE: If setRadius does not work, then radius is the default value of 1. 
  //       If setHeight does not work, then height is the default value of 1.
}

// copy constructor; I included this to show what a copy constructor does
FCylinder::FCylinder(const FCylinder& fc)
{
  // we're allowed to use the dot operator here because we're within 
  // the "same" class

  radius = fc.radius;
  height = fc.height;
}

// deconstructor
FCylinder::~FCylinder()
{
  cout << "Destroyed a FCylinder.\n";
}

//---------------------Getter Methods---------------------//
// returns radius
double FCylinder::getRadius()
{
  return radius;
}

// returns height (TO-DO)
double FCylinder::getHeight()
{
  return radius;
}

//---------------------Setter Methods---------------------//
// set radius (as long as r > 0, else keep original)
void FCylinder::setRadius(double r)
{
  if(r > 0)
  {
    radius = r;
  }
  else
  {
    cout << "Attempted to assign invalid radius size! Retaining current radius value.\n";
  }
}

// set height (as long as h > 0, else keep original)
void FCylinder::setHeight(double h)
{
  if(h > 0)
  {
    height = h;
  }
  else
  {
    cout << "Attempted to assign invalid height size! Retaining current height value.\n";
  }
}
    
//----------------------Misc. Methods---------------------//
// returns surface area of FCylinder
double FCylinder::computeSurfaceArea()
{
  return (2 * PI * radius * height) + (2 * PI * radius * radius);
}
// returns volume of FCylinder (TO-DO)
double FCylinder::computeVolume()
{
  // volume = pi * r^2 * h = pi * r * r * h
  return PI * radius * radius * height;
}

// prints member variables of FCylinder class to console output (TO-DO)
void FCylinder::printSelf()
{
  cout << "Radius: " << radius << endl;
  cout << "Height: " << height << endl;
}

/*
  Below is main.cpp
*/

void class_area();

int main()
{
  cout << "Start of program.";
  cout << "\n-------------------------\n";

  // Function made solely to show when the deconstructor is called
  class_area();

  cout << "\n-------------------------\n";

  // Custom exit prompt
  cout << "End of program. Press ENTER to continue.";
  cin.ignore(1000, '\n');

  return 0;
}
void class_area()
{
  // Example of each type of constructor in use
  FCylinder first_cyl;             // default constructor
  FCylinder second_cyl(7.5, 4.0);  // overloaded constructor
  FCylinder third_cyl(first_cyl);  // copy constructor

  // Print out each cylinder (before operations)

  // I added fancy prints to make it easier to read in console
  cout << "First (Before):" << endl;
  cout << "------\n";
  first_cyl.printSelf();

  cout << "Second (Before):" << endl;
  cout << "-------\n";
  second_cyl.printSelf();

  cout << "Third (Before):" << endl;
  cout << "------\n";
  third_cyl.printSelf();

  cout << endl;

  // Assign first_cyl's radius and height equal to second_cyl's (you can use '=' or getters)
  
  /* Two ways to do this:
     1) Use second_cyl's getRadius and getHeight as an argument for first_cyl's setRadius 
        and setHeight
     2) Use the assignment operator (if not implemented, this will copy all member variables 
        from the right object to the left object).
  */

  first_cyl.setHeight(second_cyl.getHeight()); //1)
  first_cyl.setRadius(second_cyl.getRadius()); //1)

  first_cyl = second_cyl;                      //2)

  // Set the radius of third_cyl equal to 14 and height to 13
  third_cyl.setRadius(14);
  third_cyl.setHeight(13);

  // Print out each cylinder's surface area and volume (NOTE: Each method returns doubles)
  cout << "first_cyl's SA and VOL:" << endl;
  cout << "-----------------------\n";
  cout << "Surface area: " << first_cyl.computeSurfaceArea() << endl;
  cout << "Volume: " << first_cyl.computeVolume() << endl;

  cout << "second_cyl's SA and VOL:" << endl;
  cout << "------------------------\n";
  cout << "Surface area: " << second_cyl.computeSurfaceArea() << endl;
  cout << "Volume: " << second_cyl.computeVolume() << endl;

  cout << "third_cyl's SA and VOL:" << endl;
  cout << "-----------------------\n";
  cout << "Surface area: " << third_cyl.computeSurfaceArea() << endl;
  cout << "Volume: " << third_cyl.computeVolume() << endl;

  cout << endl;

  //Print out each cylinder again (after operations)

  //I added fancy prints to make it easier to read in console
  cout << "First (After):" << endl;
  cout << "------\n";
  first_cyl.printSelf();

  cout << "Second (After):" << endl;
  cout << "-------\n";
  second_cyl.printSelf();

  cout << "Third (After):" << endl;
  cout << "------\n";
  third_cyl.printSelf();

  cout << endl;

  cout << "Leaving scope of class_area (destroying all variables local to this function)" << endl;
}
