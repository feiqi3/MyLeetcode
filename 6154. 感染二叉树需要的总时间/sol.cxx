#include <algorithm>
#include <map>
#define LEETCODE
#include "../header.h"

   struct nn {
    TreeNode *par;
    bool flag = false;
  };
class Solution {
public:
  TreeNode *startNode;
  map<int, nn> parM;
  int _start;
  void dfs(TreeNode *n, TreeNode *par) {
    if (n == nullptr)
      return;
    //找到开始节点
    if (n->val == _start)
      startNode = n;
    //保存该节点的父元素
    parM[n->val] = {par, false};
    dfs(n->left, n);
    dfs(n->right, n);
  }
  int getDepth(TreeNode *node) {
    if (node == nullptr)
      return 0;
    auto &n = parM[node->val];
    if (n.flag == true)
      return 0;
    n.flag = true;
    //递归获取父元素/左右孩子的深度的最大值
    return max(getDepth(node->left) + 1,
               max(getDepth(node->right) + 1, getDepth(n.par) + 1));
  }
  int amountOfTime(TreeNode *root, int start) {
    _start = start;
    dfs(root, nullptr);
    parM[start].flag = false;
    //计算从初始节点到末端节点的最大深度
    return getDepth(startNode) - 1;
  }
};