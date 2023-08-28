#include "box.h"

Box::Box()
{
  num = 0;
  plantName = new char[MAX];
}

Box::Box(int num, char *plantName)
{
  this->num = num;
  this->plantName = new char[strlen(plantName) + 1];
  strcpy(this->plantName, plantName);
}

Box::~Box()
{
  if (plantName != nullptr)
  {
    delete[] plantName;
  }
}

Box::Box(const Box &box)
{
  plantName = new char[strlen(box.plantName) + 1];
  strcpy(plantName, box.plantName);
  num = box.num;
}

void Box::operator=(const Box &box)
{
  strcpy(plantName, box.plantName);
  num = box.num;
}

int Box::getNum()
{
  return num;
}

char *Box::getPlantName()
{
  return plantName;
}