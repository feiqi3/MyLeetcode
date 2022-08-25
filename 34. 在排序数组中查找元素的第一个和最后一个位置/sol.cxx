#include "../header.h"
#include <vector>

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    int mid;
    bool flag = 0;
    while (l <= r) {
      mid = (l + r) / 2;
      if (nums[mid] == target) {
        flag = 1;
        break;
      } else if (nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    if(!flag){
        return {-1,-1};
    }
    int resL = mid;
    int resR = mid;

    while (resL -1 >= 0) {
        if(nums[resL - 1] != target){
            break;
        }
        resL--;
    }
    while (resR + 1 < nums.size()) {
        if(nums[resR + 1]!= target){
            break;
        }
        resR++;
    }
    return {resL,resR};
  }
};
int main() {
  Solution s;
  std::vector<int> a{1,2,3,4};
  s.searchRange(a, 1);
}