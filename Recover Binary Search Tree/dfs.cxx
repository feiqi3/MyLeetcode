#include <limits>
#include <type_traits>
#define LEETCODE
#include "../header.h"
class Solution {
 public:
  TreeNode *pre;
  TreeNode *preA;

  TreeNode *a;
  TreeNode *b;

  void dfs(TreeNode *node) {
    if (!node) {
      return;
    }
    dfs(node->left);
    
    //如果前一个节点的值
    //大于当前节点
    //那么选出第一个有问题的节点
    //注:二叉搜索树的中序遍历为升序
    //所以前一个节点的值小于当前结点的值
    if (node->val < pre->val) {
      if (!a) {
          //第一个A为前一个节点:
          //因为为升序，错误的情况只可能为当前节点的数字比前一个结点的数字小
          //而该题的错误只有两个节点被交换，所以第一个错误节点一定是个大节点
          //又因为pre节点比当前节点大，所以选择pre
        a = pre;
        //preA节点是为了防止两个相邻错误节点
        preA = node;
      } else {
          //这种情况错误节点为小结点，与上面相反
        b = node;
      }
    }
    pre = node;
    dfs(node->right);
  }
  void recoverTree(TreeNode *root) {
    TreeNode tmp;
    a = 0;
    b = 0;
    pre = new TreeNode{numeric_limits<int>::min()};
    dfs(root);
    //b不存在，那么存在两个相邻错误节点
    if (!b) {
      swap(a->val, preA->val);
      return;
    }
    swap(a->val, b->val);
  }
};