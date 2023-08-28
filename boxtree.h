#include "box.h"

class BoxTree
{
private:
  struct Node
  {
    Box *box;
    Node *left;
    Node *right;
  };
  Node *root;

public:
  BoxTree();
  BoxTree(const BoxTree &boxTree);
  ~BoxTree();
  void operator=(const BoxTree &boxTree);
  void inorder();
  void insert(Box *box);
  void remove(int num);
  int getRange(int start, int stop, Box **range);
};