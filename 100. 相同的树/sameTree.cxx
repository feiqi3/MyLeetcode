#define LEETCODE
#include "../header.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  bool DFS(TreeNode *N, TreeNode *N2) {
    if (N == nullptr && N2 == nullptr)
      return 1;
    if ((N == nullptr && N2 != nullptr) || (N != nullptr && N2 == nullptr))
      return false;
    if (N->val != N2->val)
      return 0;
    return DFS(N->left, N2->left) && DFS(N->right, N2->right);
  }
  bool isSameTree(TreeNode *p, TreeNode *q) { return DFS(p, q);}
};