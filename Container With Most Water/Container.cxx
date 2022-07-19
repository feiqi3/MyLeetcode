#include "../header.h"
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int maxArea(vector<int> &height) {
    vector<int>::iterator left = height.begin();
    vector<int>::iterator right = height.end() - 1;
    vector<int>::iterator zero = height.begin();

    int max_area = -1;
    int max_hei = -1;
    for (; right != left;) {
      int left_len = left - zero;
      int right_len = right - zero;
      int min_hei;
      if (*left < *right) {
        min_hei = *left;
        left++;
      } else {
        min_hei = *right;
        right--;
      }
      int tmp_area = min_hei * (right_len - left_len);
      if (tmp_area > max_area) {
        max_area = tmp_area;
      }
    }
    return max_area;
  }
};

int main() {
  Solution s;
  std::vector<int> h{1, 8, 6, 2, 5, 4, 8, 3, 7};
  std::cout << s.maxArea(h);
}