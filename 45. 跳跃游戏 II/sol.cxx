#include "../header.h"
#include <algorithm>
#include <vector>

class Solution {
public:
  int jump(vector<int> &nums) {
    int s = nums.size();
    if (s == 1)
      return 0;
    int maxJump = 0;
    maxJump = nums[0];
    if (maxJump >= s - 1)
      return 1;
    int cur = 0;
    int jumps = 0;
    for (; cur < s - 1;) {
      int cur_jump = maxJump;
      //如果这一跳的的结果超过了数组的长度
      //则视为完成了这一跳，给跳数+1
      if (cur_jump >= s - 1)
        return jumps + 1;
      //进行这一跳，并且选出最远的下一跳  
      for (int i = 1 + cur; i <= cur_jump; i++) {
        int next = i + nums[i];
        if (next > maxJump) {
          cur = i;
          maxJump = next;
        }
      }
      //完成这一跳，跳数+1
      jumps += 1;
    }
    return jumps;
  }
};

int main() {
  Solution s;
  vector<int> c{2, 3, 0, 1, 4};
  s.jump(c);
  return 0;
}
