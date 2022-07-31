#include "../header.h"
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
class Solution {
public:
  int maximumGroups(vector<int> &grades) {
    std::sort(grades.begin(), grades.end());
    int delta = 1;
    std::stack<int> sum;
    int i = 1;
    sum.push(grades[0]);
    while (i < grades.size()) {
      delta += 1;
      while (1) {
        int tmp_sum = 0;
        int k = i;
        int real_delta = delta;
        if(delta + i > grades.size()){
            real_delta = grades.size() - i;
        }
        for (; k < real_delta + i; k++) {
          tmp_sum += grades[k];
        }
        i = k;
        if (real_delta < delta || tmp_sum < sum.top()) {
          i = i-real_delta;
          int m_sum = sum.top() + grades[i];
          sum.pop();
          sum.push(m_sum);
          delta++;
          i++;
          break;
        } else {
          sum.push(tmp_sum);
          break;
        }
      }
    }
    return sum.size();
  }
};

int main() {
  std::vector<int> a{1,2,4,5,6};
  Solution s;
  cout << s.maximumGroups(a);
}