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
  Box();
  Box(int num, char *plantName);
  ~Box();
  Box(const Box &box);
  void operator=(const Box &box);
  int getNum();
  char *getPlantName();
};