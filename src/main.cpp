

// Copyright 2021 Artyom Lavrov


#include <iostream>
#include <random>
#include <ctime>
#include "train.h"


int main() {
  srand(time(0));

  Train* train = new Train;
  train->CreateCages(std::rand() % 500 + 1);
  std::cout << "The train's length : " << train->CountLength();
  train->Print();
  return 0;
}

