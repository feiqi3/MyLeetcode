#include "../header.h"
#include <vector>

class Solution {
public:
  int minimumRecolors(string blocks, int k) {
    int res_min = INT_MAX;
    for (int i = 0; i <= blocks.size() - k; i++) {
      int tmp = 0;
      for (int j = i; j < i + k; j++) {
        if (blocks[j] == 'W')
          tmp++;
      }
      if (tmp < res_min) {
        res_min = tmp;
      }
    }
    return res_min;
  }
};