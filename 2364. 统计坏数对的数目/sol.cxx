#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
class Solution {
public:
  long long countBadPairs(vector<int> &nums) {
    long long res = (long long)nums.size() * (nums.size() - 1) / 2;
    vector<int> mVec;
    map<int, int> mMap;
    for (int i = 0; i < nums.size(); i++) {
      int c = nums[i] - i;
      res = res - mMap[c];
      mMap[c]++;
    }
    return res;
  }
};

int main() {}