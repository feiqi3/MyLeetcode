#include "../header.h"
#include <string>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res("");
        
        int min_len = 201;
        for(auto& i : strs){
            if(i.length() < min_len)
            {
                min_len = i.length();
            }
        }
        for (int k = 0;k < min_len; k ++) {
            char tmp = strs[0][k];
            for(auto& i: strs)
            {
                if(i[k] != tmp)
                {
                    break;
                }
            }
            res+=tmp;
        }
        return res;
    }
};