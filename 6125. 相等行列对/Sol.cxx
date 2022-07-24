#include "../header.h"
#include <iostream>
#include <limits>
#include <map>
#include <vector>
class Solution {
  struct pair {
    int i;
    int j;
  };

public:
  // i行，j列
  vector<pair> mpair;
  int s;
  bool getBothEndandHead(vector<vector<int>> &grid, int num, int i, int j) {
    return (grid[i][num - 1] == grid[num- 1][j]) && (grid[i][0] == grid[0][j]);
  }
  bool checkIfE(vector<vector<int>> &grid, pair p) {
    for (int i = 0; i < s; i++) {
      if (grid[p.i][i] != grid[i][p.j]) {
        return false;
      }
    }
    return true;
  }
  int equalPairs(vector<vector<int>> &grid) {
    s = grid.size();
    for (int i = 0; i < s; i++) {
      for (int j = 0; j < s; j++) {
        if (getBothEndandHead(grid, s, i, j)) {
          mpair.push_back({i, j});
        }
      }
    }
    int res = 0;
    for (auto i : mpair) {
      if (checkIfE(grid, i))
        res += 1;
    }
    return res;
  }
};

int main()
{
    vector<vector<int>>grid{{3,2,1},{1,7,6},{2,7,7}};
    Solution s;
    s.equalPairs(grid);
}