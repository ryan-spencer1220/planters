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
  BoxTree();
  BoxTree(const BoxTree &boxTree);
  ~BoxTree();
  void operator=(const BoxTree &boxTree);
  void insert(Box &box);
  void insert(TreeNode *&root, Box &box);
  bool remove(int num);
  bool remove(TreeNode *&root, int num);
  void deleteNode(TreeNode *&target);
  int getHeight(TreeNode *root);
  BoxList getRange(const int start, const int stop);
  BoxList getRange(TreeNode *root, const int start, const int stop, BoxList &boxList);
  void printLevelSpacers(int spacers);
  void printLeaves(TreeNode *root, int level);
  TreeNode *getRoot();
};