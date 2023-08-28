#include "boxtree.h"
#include <iostream>
using namespace std;

class PlanterMgr
{
private:
  BoxTree boxTree;

public:
  PlanterMgr();
  ~PlanterMgr();
  void plant(int num, char *name);
  void harvest(char *name, int start, int stop);
  void prune(int num);
};