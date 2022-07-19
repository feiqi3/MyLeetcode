#include "../header.h"
#include <vcruntime_string.h>

class Solution {
public:
  unsigned char dp[21][31];
  bool isMatch(string s, string p) {
    dp[0][0] = 1;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < s.size() + 1; i++) {
      for (int j = 1; j < p.size() + 1; j++) {
        if (p[j] != '*') {
          if (p[j] == '.') {
            dp[i][j] = i == 0 ? 0 : dp[i - 1][j - 1];
          } else {
            if (p[j] == s[i]) {
              dp[i][j] = i == 0 ? 0 : dp[i - 1][j - 1];
            }
          }
        } else if (p[j] == '*') {
          if (p[j - 1] == s[i]) {
            dp[i][j] = dp[i][j - 1];
          }
        }
      }
    }
    return dp[s.size()][p.size()] == 1;
  }
};