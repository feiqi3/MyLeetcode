#include "../header.h"
#include "cmath"
#include <algorithm>
#include <vector>

//双指针

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    int s = nums.size();
    if (s == 3)
      return nums[0] + nums[1] + nums[2];
    std::sort(nums.begin(), nums.end());
    int delta = INT_MAX;
    int res;
    for (size_t l = 0; l < s - 2; l++) {
      int mid = l + 1;
      int r = s - 1;
      while (l < r) {
        int sum = nums[l] + nums[mid] + nums[r];
        if (abs(target-sum) < delta) {
          delta = abs(target-sum);
          res = sum;
        }
        if (sum > target) {
          r--;
        } else if (sum < target) {
          mid++;
        } else {
          return target;
        }
      }
    }
    return res;
  }
};
int main() {
    Solution s;
    std::vector<int> a{-100,-98,-2,-1};
    s.threeSumClosest(a, 1);
}