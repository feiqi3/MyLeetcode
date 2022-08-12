#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    for (int i = 0; i < grid.size(); i++) {
      grid[i][0] = i != 0 ? grid[i][0] + grid[i - 1][0] : grid[i][0];
      for (int j = 1; j < grid[0].size(); j++) {
        int y = grid[i][j];
        if (i != 0)
          y = grid[i][j] + grid[i - 1][j];
        int x = grid[i][j - 1] + grid[i][j];
        if (i != 0) {
          grid[i][j] = min(y, x);
          continue;
        }
        grid[i][j] = x;
      }
    }
    return grid[grid.size() - 1][grid[0].size() - 1];
  }
};
int main() {
  Solution s;
  vector<vector<int>> a{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  s.minPathSum(a);
}