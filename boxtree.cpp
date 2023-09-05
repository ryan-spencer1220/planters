#include "boxtree.h"

BoxTree::BoxTree()
{
  root = nullptr;
}

BoxTree::~BoxTree()
{
  if (root != nullptr)
  {
    delete root;
  }
}

BoxTree::BoxTree(const BoxTree &boxTree)
{
  root = new TreeNode;
  root->box = boxTree.root->box;
  root->left = boxTree.root->left;
  root->right = boxTree.root->right;
}

void BoxTree::operator=(const BoxTree &boxTree)
{
  root = new TreeNode;
  root->box = boxTree.root->box;
  root->left = boxTree.root->left;
  root->right = boxTree.root->right;
}

void BoxTree::insert(Box &box)
{
  insert(root, box);
}

void BoxTree::insert(TreeNode *&root, Box &box)
{
  if (!root)
  {
    root = new TreeNode(box);
  }
  else if (box.getNum() < root->box.getNum())
  {
    insert(root->left, box);
  }
  else
  {
    insert(root->right, box);
  }
}

bool BoxTree::remove(int num)
{
  return remove(root, num);
}

bool BoxTree::remove(TreeNode *&root, int num)
{
  bool flag = false;
  if (root)
  {
    if (num == root->box.getNum())
    {
      deleteNode(root);
      flag = true;
    }
    else if (num < root->box.getNum())
    {
      flag = remove(root->left, num);
    }
    else
    {
      flag = remove(root->right, num);
    }
  }
  return flag;
}

void BoxTree::deleteNode(TreeNode *&target)
{
  TreeNode *temp;

  if (!target->left && !target->right)
  {
    delete target;
    target = NULL;
  }
  else if (!target->left)
  {
    temp = target;
    target = target->right;
    temp->right = NULL;
    delete temp;
  }
  else if (!target->right)
  {
    temp = target;
    target = target->left;
    temp->left = NULL;
    delete temp;
  }
  else
  {
    TreeNode *prev = NULL;
    TreeNode *curr = target->right;
    while (curr->left)
    {
      prev = curr;
      curr = curr->left;
    }

    target->box = curr->box;

    if (!prev)
      target->right = curr->right;
    else
      prev->left = curr->right;

    curr->right = NULL;
    delete curr;
  }
}

BoxList BoxTree::getRange(const int start, const int stop)
{
  BoxList boxList;
  getRange(root, start, stop, boxList);
  return boxList;
}

void BoxTree::getRange(TreeNode *root, const int start, const int stop, BoxList &boxList)
{
  if (root)
  {
    if (root->box.getNum() > start)
    {
      getRange(root->left, start, stop, boxList);
    }
    if (root->box.getNum() >= start && root->box.getNum() <= stop)
    {
      boxList.insertAtTail(root->box);
    }
    if (root->box.getNum() < stop)
    {
      getRange(root->right, start, stop, boxList);
    }
  }
}