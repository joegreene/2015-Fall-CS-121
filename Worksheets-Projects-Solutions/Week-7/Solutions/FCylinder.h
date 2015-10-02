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
