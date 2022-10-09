#include "../header.h"
#include <algorithm>
#include <vector>

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int s = nums.size();
    if (s == 1 || nums[0] >= s - 1)return true;
    int cur = 0;
    int max_jump = nums[0];
    while (1) {
      cur++;
      if (cur > max_jump)return false;
      if (cur == s - 1)break;
      int cur_jump = cur + nums[cur];
      if (cur_jump > max_jump)max_jump = cur_jump;
      if (cur == max_jump && nums[cur] == 0)return false;
    }
    return true;
  }
};