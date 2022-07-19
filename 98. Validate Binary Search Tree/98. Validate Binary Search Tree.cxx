#include <limits>
#define LEETCODE
#include "../header.h"
class Solution {
public:
  bool dfs(TreeNode *node, long max, long min) {
    if(!node)return true;
    if (node->val < min || node->val > max) {
      return false;
    }
    return dfs(node->left, node->val, min) && dfs(node->right, max, node->val);
  }
  bool isValidBST(TreeNode *root) {
    return dfs(root, std::numeric_limits<long>::max(),
               std::numeric_limits<long>::min());
  }
};