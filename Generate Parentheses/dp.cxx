#include "../header.h"
#include <iostream>
#include <string>
#include <vector>
/*
思路:
放括号的位置无非两种
1.在“（）”的里面
2.在“（）”的外边
先求出所有i < n时的括号情况
状态转移方程为
[当i=a时的所有情况]+"("+[当i=b时的所有情况]+")"
a + b = n - 1
i = n的情况为最终的结果
*/
class Solution {
public:
  vector<string> generateParenthesis(int n) {
    if (n == 0)
      return {};
    if (n == 1)
      return {"()"};
    vector<vector<string>> vec(n + 1);
    vec[0] = {""};
    vec[1] = {"()"};
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        for (auto p : vec[j]) {
          for (auto q : vec[i - j - 1]) {
            string s = q + "(" + p + ")";
            vec[i].push_back(s);
          }
        }
      }
    }
    return vec[n];
  }
};

int main() {
  Solution s;
  auto v = s.generateParenthesis(4);
  for (auto i : v) {
    cout << i;
  }
}