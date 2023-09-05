#include "boxtree.h"
#include "box.h"
#include <iostream>
using namespace std;

class PlanterMgr
{
private:
  BoxTree boxTree;

public:
  void plant(int num, char *name);
  void harvest(char *name, int start, int stop);
  void prune(int num);
};