#include <iostream>
#include <cstring>
#pragma once

const int MAX = 100;

class Box
{
private:
  int num;
  char *plantName;

public:
  // constructors & destructor
  Box();
  Box(const Box &box);
  Box(int num, char *plantName);
  ~Box();
  // copy constructor
  void operator=(const Box &box);
  // getters
  int getNum();
  char *getPlantName();
};