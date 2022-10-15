#include <algorithm>
#include <limits>
#define LEETCODE
#include "../header.h"

class Solution {
public:
  int Imax;
  int dfs(TreeNode *&n) {
    if (n == nullptr) {
      return 0;
    }
    int leftMax = dfs(n->left);
    int rightMax = dfs(n->right);
    int val = n->val;
    int lrMax = max(leftMax,rightMax);
    Imax = max(max(leftMax + rightMax + val,Imax),val);
    Imax = max(val + lrMax,Imax);
    return max(val + lrMax,val);
  }

  int maxPathSum(TreeNode *root) {
    Imax = root->val;
    dfs(root);
    return Imax;
  }
};