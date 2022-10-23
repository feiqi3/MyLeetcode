#include "../header.h"
#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<vector<int>> DP(3,std::vector<int>(7,1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j <n ; j++) {
                DP[i][j] = DP[i-1][j] + DP[i][j-1];
            }
        }
        return DP[m-1][n-1];
    }
};