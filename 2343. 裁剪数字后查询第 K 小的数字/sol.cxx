
#include "../header.h"
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
class Solution {
public:
  // Bucket sort
  vector<int> smallestTrimmedNumbers(const vector<string> &nums,
                                     const vector<vector<int>> &queries) {
    int numLength = nums[0].size();
    vector<vector<int>> vecs(numLength + 1);
    //右边裁剪0个数字，那么就为原本的顺序
    for (int i = 0; i < nums.size(); i++) {
      vecs[0].push_back(i);
    }
    for (int j = 1; j <= numLength; j++) {
      vector<vector<int>> Bucket(10, std::vector<int>()); //桶子里放数字的下标
      for (int x : vecs[j - 1]) {
        //根据上一次桶排序的结果
        //进行这次桶排序
        Bucket[nums[x][numLength - j] - '0'].push_back(x);
      }
      for (auto &i : Bucket)
        for (auto x : i) {
          vecs[j].push_back(x);
        }
    }
    vector<int> res;
    for (auto &q : queries) {
      res.push_back(vecs[q[1]][q[0] - 1]);
    }
    return res;
  }
};

int main() {
  Solution s;
  std::cout << s.smallestTrimmedNumbers(
      vector<string>{"102", "473", "251", "814"},
      vector<vector<int>>{{2, 3}})[0];
}