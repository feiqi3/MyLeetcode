#include "../header.h"

class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  int depthG = -1;
  std::vector<std::vector<Node *>> nn;
  void dfs(Node *node, int dep) {
    if (node == nullptr) {
      return;
    }
    if (depthG < dep) {
      depthG = dep;
      nn.push_back(std::vector<Node *>());
      nn[dep].push_back(node);
    } else {
      node->next = nn[dep].back();
      nn[dep].push_back(node);
    }
    dfs(node->right, dep + 1);
    dfs(node->left, dep + 1);
  }

  Node *connect(Node *root) { dfs(root, 0); }
};