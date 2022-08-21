#define LEETCODE
#include "../header.h"

/*
TODO
TODO
TODO
TODO
*/


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
  int getDepth(TreeNode *node) {
    if (node == nullptr)
      return 0;
    return max(getDepth(node->left) + 1, getDepth(node->right) + 1);
  }
  int getFirstDepth(TreeNode *node, int &first) {
    if (node == nullptr)
      return 0;
    if(node->val == first){
        return 1;
    }
    int m = max(getDepth(node->left), getDepth(node->right));
    return m > 0 ? m + 1 : 0;
  }
  int amountOfTime(TreeNode *root, int start) {

  }
};