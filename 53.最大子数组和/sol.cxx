#include "../header.h"
#include <algorithm>
#include <limits>
#include <vector>
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    std::size_t s = nums.size();
    if (s == 1)
      return nums[0];
    int mmax = std::numeric_limits<int>::min();
    int fn = 0;
    for (int i = 0; i < s; i++) {
      //转移方程
      //fn = fn-1 + nums[i]
      fn = fn + nums[i];
      //但是当 fn < nums[i]
      //那么说明 fn <0 ，此时 nums[i] 大
      //那么就可以“另起炉灶”，从当前元素再进行计算
      fn = max(fn,nums[i]);
      mmax = std::max(fn, mmax);
    }
    return mmax;
  }
};