#include "../header.h"
#include <map>
#include <vector>
class Solution {
public:
  vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
    map<int, vector<int>> groupBy;
    for (int i = 0; i < groupSizes.size(); i++) {
      groupBy[groupSizes[i]].push_back(i);
    }
    vector<vector<int>> res;
    for (auto &i : groupBy) {
      int k = 0;
      for (int n = 0; n < i.second.size() / i.first; n++) {
        vector<int> tmp;
        for (int j = 0; j < i.first; j++, k++) {
          tmp.push_back(i.second[k]);
        }
        res.push_back(tmp);
      }
    }
    return res;
  }
};