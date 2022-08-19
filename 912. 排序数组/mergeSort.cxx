#include "../header.h"
#include <vector>

class Solution {

  std::vector<int> merge(std::vector<int> &left, std::vector<int> &right) {
    std::vector<int> mArray;
    auto lItr = left.begin();
    auto rItr = right.begin();
    while (lItr != left.end() && rItr != right.end()) {
      if (*lItr < *rItr) {
        mArray.push_back(*lItr);
        lItr++;
      } else {
        mArray.push_back(*rItr);
        rItr++;
      }
    }
    while (lItr != left.end()) {
      mArray.push_back(*lItr);
      lItr++;
    }
    while (rItr != right.end()) {
      mArray.push_back(*rItr);
      rItr++;
    }
    return mArray;
  }
std::vector<int> divide(const std::vector<int>& arr ){
    if (arr.size() == 1) {
        return arr;
    }
    
    auto lArr = divide(std::vector<int>(arr.begin(),arr.begin() + arr.size() / 2));
    auto rArr = divide(std::vector<int>(arr.begin() + arr.size() / 2,arr.end()));
    auto res = merge(lArr, rArr);
    return res;
}
public:
  vector<int> sortArray(vector<int> &nums) {
    if (nums.size() == 0) {
    return std::vector<int>{};
    }
   return  divide(nums);
  }
};