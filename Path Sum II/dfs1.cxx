#include <vector>
#define LEETCODE
#include "../header.h"
#include <queue>
#include <stack>

//这个版本太慢了
//优化：用一个全局vector<int>代替queue
//如果到末尾了就把它push_back到vector<vector<int>>里
//然后这个vector<int>里最后添加的元素pop出来(相当于回溯)
typedef queue<int> sti;

class Solution {
public:
  int tar;
  vector<sti> final;
  void dfs(TreeNode *n, int sum, sti stk) {
    if(!n)return;
    sum += n->val;
    stk.push(n->val);
    if (n->left == 0 && n->right == 0) {
      if (sum == tar) {
        final.push_back(stk);
      }
      return;
    }
    dfs(n->left, sum, stk);
    dfs(n->right, sum, stk);
  }
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    if(!root)return vector<vector<int>>();
    tar = targetSum;
    sti a;
    vector<vector<int>> res;
    dfs(root, 0, a);
    for (sti &i : final) {
      vector<int> tmp;
      while (!i.empty()) {
        tmp.push_back(i.front());
        i.pop();
      }
      res.push_back(tmp);
    }
    return res;
  }
};