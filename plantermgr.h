#include <iostream>
using namespace std;

class PlanterMgr
{
private:
public:
  PlanterMgr();
  ~PlanterMgr();
  void plant(int num, char *name);
  void harvest(char *name, int start, int stop);
  void prune(int num);
};