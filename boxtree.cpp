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

void BoxTree::insert(Box *box)
{
  Node *node = new Node;
  node->box = box;
  node->left = nullptr;
  node->right = nullptr;

  if (root == nullptr)
  {
    root = node;
  }
  else
  {
    Node *current = root;
    Node *parent = nullptr;

    while (true)
    {
      parent = current;

      if (box->getNum() < current->box->getNum())
      {
        current = current->left;

        if (current == nullptr)
        {
          parent->left = node;
          break;
        }
      }
      else
      {
        current = current->right;

        if (current == nullptr)
        {
          parent->right = node;
          break;
        }
      }
    }
  }
}

void BoxTree::remove(int num)
{
}

int BoxTree::getRange(int start, int stop, Box **range)
{
  return 0;
}

void BoxTree::printLeaves()
{
  if (root != nullptr)
  {
    return;
  }
}