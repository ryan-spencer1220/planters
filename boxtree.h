#include "box.h"
#include "boxlist.h"
#include <iostream>

using namespace std;

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
  bool insert(Box box);
  void remove(int num);
  // BoxList getRange(int start, int stop);
  void printLeaves(Node *root);
  int getHeight(Node *root);
  Node *getRoot();
};