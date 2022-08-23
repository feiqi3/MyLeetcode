#include "../header.h"
#include <algorithm>
#include <vector>

//思路 先排序，然后贪心  


class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    int i = 0;
    //按每个子数组的第一个元素大小排序
    std::sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) -> auto {
      if (a[0] < b[0])
        return true;
      return false;
    });
    int save = 0;
    while (i < intervals.size() - 1) {
      save = i;
      int max = intervals[i][1];
      //每次找到最长的覆盖
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
        //插入新数组，删除原数组
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