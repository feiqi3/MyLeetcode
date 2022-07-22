
#include "../header.h"
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
class Solution {
public:
  struct pir {
    int num;
    int pos;
    ;
  };
  int s2i(const string &s) {
    int res = 0;
    int si = s.size();
    for (int i = s.size() - 1; i >= 0; --i) {
      res += (s[i] - '0') * pow(10, si - i - 1);
    }
    return res;
  }
  vector<int> smallestTrimmedNumbers(const vector<string> &nums,
                                     const vector<vector<int>> &queries) {
    vector<int> res;
    vector<pir> numVec;
    int p = 0;
    for (auto &s : nums) {
      numVec.push_back({s2i(s), p});
      p++;
    }
    for (auto &i : queries) {
      int getI = pow(10, i[1]);
      int x = 0;
      vector<pir> tmpVec;
      for (auto j : numVec)
        tmpVec.push_back({j.num % getI, j.pos});
      sort(tmpVec.begin(), tmpVec.end(), [](pir &p1, pir &p2) {
        if (p1.num == p2.num) {
          if (p1.pos > p2.pos)
            return true;
        } else if (p1.num > p2.num) {
          return true;
        }
        return false;
      });
      res.push_back(tmpVec[i[0]].pos);
    }
    return res;
  }
};

int main() {
  Solution s;
  std::cout << s.smallestTrimmedNumbers(
      vector<string>{"24","37","96","04"},
      vector<vector<int>>{{2, 1}})[0];
}