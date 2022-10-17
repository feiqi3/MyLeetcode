#include <vector>
#define LEETCODE  
#include "../header.h"

class Solution {
public:
    int mres = 0;
    void DFS(TreeNode*& n,const int& res){
        if(n == nullptr)return;
        if(n->left == nullptr && n->right == nullptr){
            mres += res * 10 + n->val;
            return;
        }
        DFS(n->left, res * 10 + n->val);
        DFS(n->right, res * 10 + n->val);
    }
    int sumNumbers(TreeNode* root) {
        DFS(root, 0);
        return mres;
    }
};
