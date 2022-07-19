#include "../header.h"
#include <string>
#include <vector>
class Solution {
public:
  void dfs(int left, int right, string str, vector<string> &strV) {
    if (left == 0 && right == 0) {
      strV.push_back(str);
      return;
    }
    if (left > 0) {
      str += '(';
      dfs(left - 1, right, str, strV);
      str.erase(str.size() - 1, 1);
    }
    if (right > left) {
      str += ')';
      dfs(left, right - 1, str, strV);
    }
  }
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    string tmp="";
    dfs(n, n, tmp, res);
    return res;
  }
};
int main() {
  Solution s;
  auto v = s.generateParenthesis(2);
  for (auto &i : v) {
    std::cout << i << "\n";
  }
}