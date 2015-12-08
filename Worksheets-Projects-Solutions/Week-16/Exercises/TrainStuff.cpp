/*
  Class Implementation file (for Train class)
*/

#include "TrainStuff.h"

// Constructors and Destructors
Train::Train()                      // constructor
{
  num_cars = 0;
  engine = NULL;
}
Train::~Train()                     // destructor - properly delete the Train when finished
{
  // we have two pointers required for deleting the train
  TrainCar* michael_bay = NULL;
  TrainCar* conductor = engine;

  // while the conductor cannot move to any more train cars
  while (conductor != NULL)
  {
    // Michael Bay impersonates the conductor
    michael_bay = conductor;
    // the real conductor moves onto the next train car
    conductor = conductor->next;
    // Michael Bay, for box office money, blows up the train car the conductor just left
    delete michael_bay;
  }
}

// misc. getters
int Train::getEngineCarID()        // returns car ID of front train car
{
  if (noCars())
  {
    cout << "No cars on train. Returning -1.\n";
    return -1;
  }
  else
  {
    return engine->car_num;
  }
}

// misc. methods
void Train::attach(int id)             // create and attach a TrainCar to end of train
{
  if (noCars())
  {
    // create a new car if none exists yet
    engine = new TrainCar(id);
  }
  else
  {
    // create a new car and attach to end of train
    TrainCar* car = engine;
    
    // navigate to last node of linked list
    while(car->next != NULL)
    {
      car = car->next;
    }

    car->next = new TrainCar(id);
  }

  num_cars++;
}
void Train::detachLast()              // remove last TrainCar from end of train
{
  if (noCars())
  {
    cout << "No cars in train to detach!\n";
  }
  else
  {
    // one for deletion, the other for navigating to the last node
    TrainCar* car = engine;
    TrainCar* prev = NULL;  
    
    // navigate to last node of linked list
    while (car->next != NULL)
    {
      prev = car;
      car = car->next;
    }

    delete car;
    prev->next = NULL;

    --num_cars;
  }
}
bool Train::noCars()                  // returns true if no cars in Train
{
  return (num_cars == 0);
}
void Train::printTrain()              // prints all train cars in train list
{
  TrainCar* temp = engine;
  cout << "List of train cars the train has: " << endl;

  // go through all train cars belonging to the train
  while (temp != NULL)
  {
    cout << "Train car number: " << temp->car_num << endl;
    temp = temp->next;
  }
}
