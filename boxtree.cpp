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
  if (root != nullptr)
  {
    return;
  }
  Node *current = root;
  Node *parent = nullptr;
  while (current)
  {
    parent = current;
    if (current->left != nullptr)
    {
      current = current->left;
    }
    else if (current->right != nullptr)
    {
      current = current->right;
    }
    else
    {
      current = parent;
    }
  }
}

bool BoxTree::insert(Box box)
{
  Node *newNode = new Node();
  newNode->box = &box;
  if (root == nullptr)
  {
    root = newNode;
    return true;
  }
  Node *temp = root;
  while (true)
  {
    if (newNode->box < temp->box)
    {
      if (temp->left == nullptr)
      {
        temp->left = newNode;
        return true;
      }
      temp = temp->left;
    }
    else
    {
      if (temp->right == nullptr)
      {
        temp->right = newNode;
        return true;
      }
      temp = temp->right;
    }
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

void BoxTree::printLeaves(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  // Print left subtree
  printLeaves(root->left);

  // Print root node
  cout << root->box->getNum() << " ";

  // Print right subtree
  printLeaves(root->right);
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