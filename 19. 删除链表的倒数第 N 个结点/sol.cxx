#include "../header.h"
#include <vector>

class Solution {
public:
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes(30);
        auto tmp = head;
        int i =0;
        while (1) {
            if(tmp == nullptr)break;
            nodes[i] = tmp;
            ++i;
            tmp = tmp->next;
        }
        if(n == i){
            return head->next;
        }
        nodes[i - n - 1]->next = nodes[i - n]->next;
        return head;
    }
};