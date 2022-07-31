#include "../header.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <type_traits>
#include <vector>


class Solution {
public:
  map<int, int> m1;
  map<int, int> m2;
  int closestMeetingNode(vector<int> &edges, int node1, int node2) {
    int i = node1;
    int step = 0;
    while (i != -1) {
      if (m1.find(i) != m1.end()) {
        break;
      }
      m1[i] = step;
      step++;
      i = edges[i];
    }
    i = node2;
    step = 0;
    while (i != -1) {
      if (m2.find(i) != m2.end()) {
        break;
      }
      m2[i] = step;
      step++;
      i = edges[i];
    }
    int min_ = INT_MAX;
    int res = -1;
    for (auto i : m1) {
      if (m2.find(i.first) != m2.end()) {
        auto tmp = max(i.second, m2[i.first]);
        if ( tmp < min_) {
          swap(min_, tmp);
          res = i.first;
        }
      }
    }
    return res;
  }
};
int main(){
    vector<int> a{5,4,5,4,3,6,-1};
    Solution s;
    cout<<s.closestMeetingNode(a, 0, 1);
}