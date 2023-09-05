#include "box.h"

class TreeNode
{
public:
  // data members
  Box box;
  TreeNode *left;
  TreeNode *right;

  // constructors & destructor
  TreeNode();
  TreeNode(Box &box);
  ~TreeNode();

  // copy constructor & assignment operator
  TreeNode(const TreeNode &treeNode);
  void operator=(const TreeNode &treeNode);
};