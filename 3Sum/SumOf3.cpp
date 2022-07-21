#include "../header.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <xmemory>
//去重是看了题解才会的
//太难了这题
//主要是去重555
class Solution {
public:
  int clamp(int a, int b, int c) { return min(max(a, c), b); }
  vector<vector<int>> threeSum(vector<int> &nums) {
    if (nums.size() < 3)
      return vector<vector<int>>();
    std::sort(nums.begin(), nums.end());
    if (*nums.begin() > 0 || *(nums.end() - 1) < 0)
      return vector<vector<int>>();
    if (*nums.begin() == 0 && *(nums.end() - 1) == 0) {
      return vector<vector<int>>(1, vector<int>{0, 0, 0});
    }
    std::vector<int>::iterator lsat = nums.begin();
    vector<vector<int>> res;
    int left = 0;
    int right = nums.size() - 1;
    for (int i = 0; i < nums.size() - 1; i++) {
      int left = i + 1;
      int right = nums.size() - 1;

      for (; left < right;) {
        int sum = nums[i] + nums[left] + nums[right];
        if (sum == 0) {
          res.push_back(vector<int>{nums[i], nums[left], nums[right]});
          while (left < right&&nums[left] == nums[left + 1]) {
            left++;
          }
          while (left < right&&nums[right] == nums[right - 1]) {
            right--;
          }
          while(nums[i] ==nums[i + 1])
          {
            i++;
          }
          left++;
          right --;
        } else if (sum > 0) {
          right--;
        } else if (sum < 0) {
          left++;
        }
      }
    }
    return res;
  }
};