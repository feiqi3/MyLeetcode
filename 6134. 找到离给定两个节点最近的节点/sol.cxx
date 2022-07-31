#include "../header.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <type_traits>
#include <vector>


class Solution {
public:
  int closestMeetingNode(vector<int> &edges, int node1, int node2) {
  vector<int> m1(edges.size(),-1);
  vector<int> m2(edges.size(),-1);
    int i = node1;
    int step = 0;
    while (i != -1) {
      if (m1[i] != -1) {
        break;
      }
      m1[i] = step;
      step++;
      i = edges[i];
    }
    i = node2;
    step = 0;
    while (i != -1) {
      if (m2[i]!=-1) {
        break;
      }
      m2[i] = step;
      step++;
      i = edges[i];
    }
    int min_ = INT_MAX;
    int res = -1;
    for (int i = 0; i < m1.size(); i++) {
        if(m1[i] == -1 || m2[i] == -1)continue;
        auto tmp = max(m1[i],m2[i]);
        if(tmp<min_){
            res = i;
            min_ = tmp;
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