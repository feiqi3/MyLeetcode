#include "../header.h"
#include <set>
#include <vector>

class Solution {
public:
  string smallestNumber(string pattern) {
    std::vector<string> numsVec{"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    vector<int> nums;
    string res = "";
    int i = 0;
    while (i <= pattern.size()) {
      if (pattern[i] == 'I') {
        res += numsVec[i];
        i++;
      } else {
        int sPos = i;
        while (i < pattern.size() && pattern[i] == 'D') {
          i++;
        }
        int s = i;
        while (s >= sPos) {
          res += numsVec[s];
          s--;
        }
        i++;
      }
    }
    return res;
  }
};