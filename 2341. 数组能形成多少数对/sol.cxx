#include "../header.h"
#include <algorithm>
#include <vector>

class Solution {
public:
  vector<int> numberOfPairs(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int remain = nums.size();
    int pairs = 0;
    int last = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (remain > 1 && nums[i] == last) {
        pairs++;
        remain -= 2;
        if (i + 1 < nums.size()) {
          last = nums[i + 1];
          i += 1;
          continue;
        }else {
        break;
        }
      }
      last =nums[i];
    }
    return std::vector<int>{pairs, remain};
  }
};

int main() {
  vector<int> numb{12,3,12,12,72,72,72,72,72,72};
  Solution s;
  s.numberOfPairs(numb);
}