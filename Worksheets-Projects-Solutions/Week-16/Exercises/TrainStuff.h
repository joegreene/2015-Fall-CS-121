/*
  Class header file (Train and TrainCar)
*/
#include <iostream>
using namespace std;

// class prototypes (specifically for the friend statement in TrainCar)
class TrainCar;
class Train;

class TrainCar
{
    friend Train;   // avoid using getters/setters in Train

    int car_num;
    TrainCar* next; // use this to "link" more train cars together
  
    TrainCar(int car_num) // leaving this as private (so only Train may use it)
    {
      this->car_num = car_num;
      next = NULL;
    }
};

class Train
{
    TrainCar* engine;               // first train car
    int num_cars;                   // number of train cars

  public:
    Train();                        // default constructor
    ~Train();                       // destructor - properly delete the Train when finished

    // misc. getters
    int getEngineCarID();           // returns car ID of front train car

    // misc. methods
    void attach(int x);             // create and add TrainCar to end of train
    void detachLast();              // remove last TrainCar from end of train
    bool noCars();                  // returns true if the train has no cars
    void printTrain();              // prints all train car IDs the train has
                                    // NOTE: You can technically overload "operator<<" here
};
