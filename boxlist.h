#include "box.h"

class BoxList
{
private:
  struct Node
  {
    Box *box;
    Node *next;
  };
  Node *head;
  Node *tail;

public:
  BoxList();
  BoxList(const BoxList &boxList);
  ~BoxList();
  void operator=(const BoxList &boxList);
  void insert(Box box);
  void remove(int num);
  void print();
};