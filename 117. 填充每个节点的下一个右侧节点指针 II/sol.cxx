#include "../header.h"
/*
你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
*/

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
  Node *findNext(Node *&n, Node *h) {
    if (n != h->right && h->right != nullptr) {
      return h->right;
    }
    while (h->next != nullptr) {
      h = h->next;
      if (h->left != nullptr)
        return h->left;
      if (h->right != nullptr)
        return h->right;
    }
    return nullptr;
  }
  void dfs(Node *&n, Node *&head) {
    if (n == nullptr) {
      return;
    }
    if (head != nullptr) {
      n->next = findNext(n, head);
    }
    dfs(n->left, n);
    dfs(n->right, n);
    return;
  }

  Node *connect(Node *root) {
    Node *p = nullptr;
    dfs(root, p);
    return root;
  }
};

int main() {
  Node root(1);
  root.left = new Node(2);
  root.right = new Node(3);
  root.left->left = new Node(4);
  root.left->right = new Node(5);
  root.left->left->left = new Node(7);
  root.right->right = new Node(6);
  root.right->right->right = new Node(8);
  Solution s;
  s.connect(&root);
}