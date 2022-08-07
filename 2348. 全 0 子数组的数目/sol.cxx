#include "../header.h"
#include <map>
#include <vector>
class Solution {
public:
  long long zeroFilledSubarray(vector<int> &nums) {
    std::map<int, int> zeroNums;
    int tmp_len = 0;
    for (auto i : nums) {
      if (i == 0) {
        tmp_len++;
      } else if (tmp_len > 0) {
        zeroNums[tmp_len]++;
        tmp_len = 0;
      }
    }
    if (tmp_len != 0)
      zeroNums[tmp_len]++;
    long long res = 0;
    for (auto &i : zeroNums) {
      long tmp_res = 0;
      int k = i.first;
      for (int j = i.first; j > 0; j--) {
        tmp_res += k - j + 1;//dp? purely cjb
      }
      res += tmp_res * i.second;
    }
    return res;
  }
};
int main() {
  Solution s;
  std::vector<int> m{0, 0, 0, 2, 0, 0};
  s.zeroFilledSubarray(m);
}