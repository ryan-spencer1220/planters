#include "treenode.h"

TreeNode::TreeNode()
{
  left = nullptr;
  right = nullptr;
}

TreeNode::TreeNode(Box &box)
{
  this->box = box;
  left = nullptr;
  right = nullptr;
}

TreeNode::~TreeNode()
{
  if (left != nullptr)
  {
    delete left;
  }
  if (right != nullptr)
  {
    delete right;
  }
}

TreeNode::TreeNode(const TreeNode &treeNode)
{
  box = treeNode.box;
  left = treeNode.left;
  right = treeNode.right;
}

void TreeNode::operator=(const TreeNode &treeNode)
{
  box = treeNode.box;
  left = treeNode.left;
  right = treeNode.right;
}