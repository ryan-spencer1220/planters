#include "plantermgr.h"

PlanterMgr::PlanterMgr()
{
}

PlanterMgr::~PlanterMgr()
{
}

void PlanterMgr::plant(int num, char *name)
{
  Box box(num, name);
  boxTree.insert(box);
  cout << "Planted " << name << " in box " << num << endl;
}

void PlanterMgr::harvest(char *name, int start, int stop)
{
  BoxList boxList = boxTree.getRange(start, stop);
  cout << "Harvesting " << name << " plants from boxes " << start << " to " << stop << endl;
  cout << "The following boxes will be harvested: " << endl;
  boxList.startIterating();
  while (boxList.hasNextBox())
  {
    Box box = boxList.getNextBox();
    if (strcmp(box.getPlantName(), name) == 0)
    {
      cout << box.getNum() << " ";
    }
  }
}

void PlanterMgr::prune(int num)
{
  bool result = false;
  result = boxTree.remove(num);
  if (result)
  {
    cout << "Pruned box " << num << endl;
  }
}