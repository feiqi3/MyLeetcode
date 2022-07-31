#include "../header.h"
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int minimumOperations(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int i = 0;
    int step = 0;
    while (i < nums.size()) {
      auto tmp = nums[i];
      if (tmp == 0) {
        i++;
        continue;
      }
      for (int k = i; k < nums.size(); k++) {
        nums[k] -= tmp;
      }
      step++;
      i++;
    }
    return step;
  }
};
int main(){
    Solution s;
    vector<int> a{1,5,0,3,5};
    std::cout<<s.minimumOperations(a);
}