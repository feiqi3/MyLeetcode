#include "../header.h"


class Solution {
public:
    void dfs(ListNode* n,int& td,const int ii){
        if(n==nullptr)return;
        int now = td;
        ++td;
        dfs(n, td,ii);
        if(td - ii - 1 == now){
            n->next = n->next->next;
        }
        return;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int a = 0;
        dfs(head, a,n);
        if(n == a)return head->next;
        return head;
    }
};