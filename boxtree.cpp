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
  root = new Node;
  root->box = boxTree.root->box;
  root->left = boxTree.root->left;
  root->right = boxTree.root->right;
}

void BoxTree::operator=(const BoxTree &boxTree)
{
  root = new Node;
  root->box = boxTree.root->box;
  root->left = boxTree.root->left;
  root->right = boxTree.root->right;
}

void BoxTree::inorder()
{
  // if (root != nullptr)
  // {
  //   return;
  // }
  // Node *current = root;
  // Node *parent = nullptr;
  // while (current)
  // {
  //   parent = current;
  //   if (current->left != nullptr)
  //   {
  //     current = current->left;
  //   }
  //   else if (current->right != nullptr)
  //   {
  //     current = current->right;
  //   }
  //   else
  //   {
  //     current = parent;
  //   }
  // }
}

void BoxTree::insert(Box &box)
{
  insert(root, box);
}

void BoxTree::insert(Node *&root, Box &box)
{
  if (root)
  {
    cout << root->box->getNum() << endl;
  }
  if (!root)
  {
    root = new Node;
    root->box = &box;
    root->left = nullptr;
    root->right = nullptr;
    return;
  }
  else if (box.getNum() < root->box->getNum())
  {
    insert(root->left, box);
  }
  else if (box.getNum() >= root->box->getNum())
  {
    insert(root->right, box);
  }
}

void BoxTree::remove(int num)
{
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

void BoxTree::printLeaves(Node *root, int level)
{
  if (root)
  {
    printLevelSpacers(level - 1);
    if (level)
      cout << "|-";
    cout << root->box->getNum() << endl;
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

int BoxTree::getHeight(Node *root)
{
  if (root == nullptr)
  {
    return 0;
  }
  return 1 + getHeight(root->left) + getHeight(root->right);
}

BoxTree::Node *BoxTree::getRoot()
{
  return root;
}