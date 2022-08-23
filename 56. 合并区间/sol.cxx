#include "../header.h"
#include <algorithm>
#include <vector>
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    int i = 0;
    std::sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) -> bool {
      if (a[0] < b[0])
        return true;
      return false;
    });
    int save = 0;
    while (i < intervals.size() - 1) {
      save = i;
      int max = intervals[i][1];
      while (i < intervals.size() - 1) {
        if (max >= intervals[i + 1][0]) {
          if (intervals[i + 1][1] > max) {
            max = intervals[i + 1][1];
          }
          i++;
        }else {
        break;
        }
      }
      if (save != i) {
        std::vector<int> mVec{intervals[save][0], max};
        intervals.insert(intervals.begin() + save, mVec);
        intervals.erase(intervals.begin() + save + 1,
                        intervals.begin() + i + 2);
      }
      i = save + 1;
    }
    return intervals;
  }
};

int main(){
    std::vector<vector<int>> tmp{{1,3},{2,6},{8,10},{15,18}};
    Solution s;
    s.merge(tmp);
}