#include "../header.h"
class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int k = gas.size();
        if (k == 1)
      return gas[0] >= cost[0] ? 0 : -1;
    std::vector<int> md(k);
    int sum = 0;
    for (int i = 0; i < k; i++) {
      md[i] = (gas[i] - cost[i]);
      sum = sum + gas[i] - cost[i];
    }
    if (sum < 0)
      return -1;
    sum = 0;
    for (int i = 0; i < k; i++) {
      if (md[i] > 0) {
        sum = 0;
        for (int j = i; j < i + k; j++) {
          sum += md[j % k];
          if (sum < 0)
            break;
        }
        if (sum >= 0)
          return i;
      }
    }
    return -1;
  }
};