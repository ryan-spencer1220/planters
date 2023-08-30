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
  void insert(Box &box);
  void insert(Node *&root, Box &box);
  void remove(int num);
  // BoxList getRange(int start, int stop);
  int getHeight(Node *root);
  Node *getRoot();
  void printLevelSpacers(int spacers);
  void printLeaves(Node *root, int level);
};