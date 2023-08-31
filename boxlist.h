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
  Node *mCurrent;

public:
  BoxList();
  BoxList(const BoxList &boxList);
  ~BoxList();
  void operator=(const BoxList &boxList);
  void insertAtTail(Box &box);
  void startIterating();
  const Box &getNextBox();
  bool hasNextBox();
};