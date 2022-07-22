#include "../header.h"
#include <iostream>
#include <limits>
#include <map>
#include <vector>
class Solution {
public:
    int getNum(int n)
    {
        int sum = 0;
        while (n > 0) {
        sum += n % 10;
        n = n / 10;
        }
        return  sum;
    }
    int maximumSum(vector<int>& nums) {
        map<int,std::vector<int>> m_map;
        for(int i  = 0;i < nums.size();i ++)
        {
           int tmp = (getNum(nums[i]));
           m_map[tmp].push_back(nums[i]);
        }
        int Mmax = std::numeric_limits<int>::min();
        int flag = false;
        for (auto i = m_map.begin();i !=m_map.end(); i++) {
            int si = i->second.size();
            if(si < 2)continue;
            flag = true;
            sort(i->second.begin(),i->second.end());
            int sum = i->second[si - 1] +i->second[si - 2];
            if(sum > Mmax)
            {
                swap(Mmax, sum);
            }
        }        
        if(!flag)return -1;
        else
         return Mmax;
    }
};

int main()
{
    std::cout<<Solution().getNum(123);
}