#include "../header.h"
#include <stack>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s = prices.size();
        if(s == 0)return 0;
        int res = 0;
        int first = 0;
        int last = 0;
        for (int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i - 1]){
                last = i;
                continue;
            }
            else {
            res += prices[i - 1] - prices[first];
            first = i;
            }
        }
        if(last > first)
            res += prices[last] - prices[first];
        return res;
    }
};