#include "../header.h"
class Solution {
public:
  stack<int> bracket;
  vector<int> pos;
  int longestValidParentheses(string s) {
    bracket.push(-1);
    int res = 0;
    for (auto i = 0; i < s.size(); i++) {
      if (s[i] == '(')
        bracket.push(i);
      else if (s[i] == ')') {
        bracket.pop();
        if (!bracket.empty()) {
          res = max(res, i - bracket.top());
        } else {
          bracket.push(i);
        }
      }
    }
    return res;
  }
};