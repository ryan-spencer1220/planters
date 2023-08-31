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
  if (!root)
    return false;
  else if (num == root->box.getNum())
  {
    deleteNode(root);
    return true;
  }
  else if (num < root->box.getNum())
    return remove(root->left, num);
  else
    return remove(root->right, num);
}

void BoxTree::deleteNode(TreeNode *&target)
{
  TreeNode *temp;

  // a leaf
  if (!target->left && !target->right)
  {
    delete target;
    target = NULL;
  }
  // no left child
  else if (!target->left)
  {
    temp = target;
    target = target->right;
    temp->right = NULL;
    delete temp;
  }
  // no right child
  else if (!target->right)
  {
    temp = target;
    target = target->left;
    temp->left = NULL;
    delete temp;
  }
  // two children
  else
  {
    // find the inorder successor
    TreeNode *prev = NULL;
    TreeNode *curr = target->right;
    while (curr->left)
    {
      prev = curr;
      curr = curr->left;
    }

    // copy data at curr (the inorder successor) into target
    target->box = curr->box;

    // disconnect curr (the inorder successor)
    if (!prev)
      target->right = curr->right;
    else
      prev->left = curr->right; // the inorder successor could have a right child

    // delete curr (the inorder successor)
    curr->right = NULL;
    delete curr;
  }
}

// BoxList BoxTree::getRange(int start, int stop)
// {
//   BoxList boxList;
//   return boxList;
// }

void BoxTree::printLevelSpacers(int spacers)
{
  for (int i = 0; i < spacers; i++)
    cout << "  ";
}

void BoxTree::printLeaves(TreeNode *root, int level)
{
  if (root)
  {
    printLevelSpacers(level - 1);
    if (level)
      cout << "|-";
    cout << root->box.getNum() << endl;
    if (root->left || root->right)
    {
      if (root->left)
        printLeaves(root->left, level + 1);
      else
      {
        printLevelSpacers(level);
        cout << '|' << endl;
      }
      if (root->right)
        printLeaves(root->right, level + 1);
      else
      {
        printLevelSpacers(level);
        cout << '|' << endl;
      }
    }
  }
}

int BoxTree::getHeight(TreeNode *root)
{
  if (root == nullptr)
  {
    return 0;
  }
  return 1 + getHeight(root->left) + getHeight(root->right);
}

TreeNode *BoxTree::getRoot()
{
  return root;
}