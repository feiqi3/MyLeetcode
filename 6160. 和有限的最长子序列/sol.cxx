#include "../header.h"
#include <algorithm>
#include <vector>

class Solution {
public:
  vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
    sort(nums.begin(), nums.end());
    vector<int> ans;
    for (int i = 0; i < queries.size(); i++) {
      int s = queries[i];
      int sum = 0;
      int step = 0;
      for (int j = 0; j < nums.size();j++) {
        int tmp = sum+nums[j];
        if(tmp > s)
            break;
        sum = tmp;
        step++;
      }
      ans.push_back(step);
    }
    return ans;
  }
};
int main() {
  vector<int> a{469781,45635,628818,324948,343772,713803,452081};
  vector<int> q{816646,929491};
  Solution s;
  s.answerQueries(a, q);
}