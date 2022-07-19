#include <vector>
#define LEETCODE
#include "../header.h"
#include <queue>
#include <stack>

typedef vector<int> sti;

class Solution {
public:
  int tar;
  vector<sti> final;
  vector<int> stk;
  void dfs(TreeNode *n, int sum) {
    if(!n)return;
    sum += n->val;
    if(sum > tar)return;
    stk.push_back(n->val);
    if(!n->left&&!n->right&&sum == tar)
    {
        final.push_back(stk);
    }
    dfs(n->left, sum);
    dfs(n->right, sum);
    stk.pop_back();
  }
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    if(!root)
    {
        return vector<vector<int>>();
    }
    tar = targetSum;
    vector<vector<int>> res;
    dfs(root, 0);
    return res;
  }
};