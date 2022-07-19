#include "../header.h"
#include <algorithm>
#include <vcruntime_string.h>

class Solution {
public:
  int longestValidParentheses(string s) {
    int *dp = new int[s.length()];
    memset(dp, 0, s.length() * sizeof(int));
    int _max = 0;
    if(s[0] == '(' && s[1] == ')')
    {
        dp[1] = 2;
        _max = 2;
    }
    for (int i = 2; i < s.length(); i++) {
      if (s[i] == ')') {
        int t = i - 1;
        if (s[t] == '(') {
          dp[i] = dp[t]+(t - 1 >= 0 ? dp[t - 1] : 0) + 2;
        } else {
          t -= dp[t];
          if (t >= 0 && s[t] == '(') {
            dp[i] = dp[i - 1] + 2 + (t -  1 >= 0 ? dp[t - 1] : 0);
          } else {
            dp[i] = 0;
          }
        }
      }else
      {
          dp[i] = 0;
      }
      _max = std::max(dp[i], _max);
    }
    return _max;
  }
};