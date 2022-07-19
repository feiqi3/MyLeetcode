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
 
#define max(a,b) (((a) > (b)) ? (a) : (b))
#include <cmath>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  void dfs(int *gn, int *fn, TreeNode *tree) {
    if (!tree) {
      *gn = 0;
      *fn = 0;
      return;
    }

    int tmpgna, tmpfna;
    dfs(&tmpgna, &tmpfna, tree->left);
    int tmpgnb, tmpfnb;
    dfs(&tmpgnb, &tmpfnb, tree->right);
    *fn = tmpgnb + tmpgna + tree->val;
    *gn = max(tmpfnb, tmpgnb) + max(tmpgna, tmpfna);
    return;
  }
  int rob(TreeNode *root) {
    int a, b;
    dfs(&a, &b, root);
    return max(a, b);
  }
};