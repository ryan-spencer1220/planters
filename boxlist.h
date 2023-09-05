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
  int mSize;

public:
  // constructors & destructor
  BoxList();
  BoxList(const BoxList &boxList);
  ~BoxList();

  // copy constructor
  void operator=(const BoxList &boxList);

  // insert and iterator functions
  void insertAtTail(Box &box);
  void startIterating();
  Box &getNextBox();
  bool hasNextBox();
};