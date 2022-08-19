#include "../header.h"
#include <vector>

class Solution {

public:
  vector<vector<int>> largestLocal(vector<vector<int>> &grid) {
    vector<vector<int>> res;
    for (int i = 1; i < grid.size() - 1; i++) {
      vector<int> tmp;
      for (int j = 1; j < grid[0].size() -1; j++) {
        int a = grid[i - 1][j - 1];
        int b = grid[i - 1][j];
        int c = grid[i - 1][j + 1];
        int d = grid[i][j - 1];
        int e = grid[i][j];
        int f = grid[i][j + 1];
        int g = grid[i + 1][j - 1];
        int h = grid[i + 1][j];
        int k = grid[i + 1][j + 1];
        tmp.push_back(max(k,max(h,max(g,max(f,max(e,max(d,max(max(a,b),c))))))));
      }
      res.push_back(tmp);
    }
    return res;
  }
};

int main() {
    std::vector<vector<int>> grid{{1,1,1,1,1},{1,1,1,1,1},{1,1,2,1,1},{1,1,1,1,1},{1,1,1,1,1}};
    Solution a;
    a.largestLocal(grid);
}