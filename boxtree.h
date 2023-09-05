#include "box.h"
#include "boxlist.h"
#include "treenode.h"
#include <iostream>

using namespace std;

class BoxTree
{
private:
  TreeNode *root;

public:
  // constructors & destructor
  BoxTree();
  BoxTree(const BoxTree &boxTree);
  ~BoxTree();

  // copy constructor
  void operator=(const BoxTree &boxTree);

  // insert and remove functions
  void insert(Box &box);
  void insert(TreeNode *&root, Box &box);
  bool remove(int num);
  bool remove(TreeNode *&root, int num);
  void deleteNode(TreeNode *&target);

  // getRange functions
  BoxList getRange(const int start, const int stop);
  void getRange(TreeNode *root, const int start, const int stop, BoxList &boxList);
};