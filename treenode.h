#include "box.h"

class TreeNode
{
public:
  Box box;
  TreeNode *left;
  TreeNode *right;

  TreeNode();
  TreeNode(Box &box);
  ~TreeNode();
  TreeNode(const TreeNode &treeNode);
  void operator=(const TreeNode &treeNode);
};