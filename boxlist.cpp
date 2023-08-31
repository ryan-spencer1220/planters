#include "boxlist.h"

BoxList::BoxList()
{
  head = nullptr;
  tail = nullptr;
  mCurrent = nullptr;
}

BoxList::BoxList(const BoxList &boxList)
{
  head = nullptr;
  tail = nullptr;
  mCurrent = nullptr;
  Node *current = boxList.head;
  while (current != nullptr)
  {
    insertAtTail(*(current->box));
    current = current->next;
  }
}

BoxList::~BoxList()
{
  Node *current = head;
  while (current != nullptr)
  {
    Node *next = current->next;
    delete current->box;
    delete current;
    current = next;
  }
}

void BoxList::operator=(const BoxList &boxList)
{
  Node *current = head;
  while (current != nullptr)
  {
    Node *next = current->next;
    delete current->box;
    delete current;
    current = next;
  }
  head = nullptr;
  tail = nullptr;
  mCurrent = nullptr;
  current = boxList.head;
  while (current != nullptr)
  {
    insertAtTail(*(current->box));
    current = current->next;
  }
}

void BoxList::insertAtTail(Box &box)
{
  Node *newNode = new Node;
  newNode->box = new Box(box);
  newNode->next = nullptr;
  if (head == nullptr)
  {
    head = newNode;
    tail = newNode;
  }
  else
  {
    tail->next = newNode;
    tail = newNode;
  }
}

void BoxList::startIterating()
{
  mCurrent = head;
}

const Box &BoxList::getNextBox()
{
  Box *box = mCurrent->box;
  mCurrent = mCurrent->next;
  return *box;
}

bool BoxList::hasNextBox()
{
  return mCurrent != nullptr;
}