/*
  Driver for Train stuff

  The purpose of this handout is just to try and understand its logic, and 
  the best way to comprehend it is by drawing diagrams.

*/

#include "TrainStuff.h"

int main()
{
  Train my_train;

  for(int i = 0; i < 27; ++i)
  {
    my_train.attach(i*1000);
  }
  for(int i = 0; i < 4; ++i)
  {
    my_train.detachLast();
  }

  my_train.printTrain();

  cout << "Press ENTER to exit program.";
  cin.ignore();

  return 0;
}