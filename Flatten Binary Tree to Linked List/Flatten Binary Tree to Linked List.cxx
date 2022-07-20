#include <iostream>
#include <type_traits>
#include <vector>
#define LEETCODE
#include "../header.h"
TreeNode* getRightest(TreeNode* node)
{
    TreeNode* tmp = node;
    while (tmp->right !=nullptr) {
        tmp = tmp->right;
    }
    return tmp;
}
void swapChildren(TreeNode *node)
{
    if(node->left == nullptr)return;
    using std::swap;
    swap(node->left,node->right);
}
class Solution {
public:
  void flatten(TreeNode *root) {
      if(!root)return;
      swapChildren(root);
      flatten(root->left);
      flatten(root->right);
      TreeNode* rightest = getRightest(root);
      rightest->right = root->left;
      root->left = NULL;
  }
};
int main()
{
    int c = 0;
    std::cout<<"Hello LLDB";
}