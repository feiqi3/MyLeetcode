#include "../header.h"
#include <vector>
class Solution {
public:
  bool isMatch(string s, string p) {
    vector<vector<int>> dp(p.length() + 1, vector<int>(s.length() + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= p.length(); i++) {
      int flag = false;
      for (int j = 1; j <= s.length(); j++) {
        if (p[i - 1] == '?') {
          dp[i][j] = dp[i - 1][j - 1];
          flag = 1|flag;
        } else if (p[i - 1] == '*') {
          dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
          flag = 1|flag;
        } else {
          if (p[i - 1] == s[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1];
            flag = 1|flag;
          }
        }
      }
      if (!flag)
        return false;
    }

    return dp[p.length()][s.length()] == 1;
  }
};