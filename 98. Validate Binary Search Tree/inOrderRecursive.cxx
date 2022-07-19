#define LEETCODE
#include "../header.h"
class Solution {
public:
  long pre = numeric_limits<long>::min();
  bool isValidBST(TreeNode *root) {
    if (!root) {
      return true;
    }
    if (!isValidBST(root->left)) {
      return false;
    }
    if (root->val > pre) {
      pre = root->val;
    } else {
      return false;
    }
    if (!isValidBST(root->right)) {
      return false;
    }
    return true;
  }
};