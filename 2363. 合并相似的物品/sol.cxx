#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
class Solution {
public:
  vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1,
                                        vector<vector<int>> &items2) {
    int sizem = max(items1.size(), items2.size());
    map<int ,int > mMap;
    for (int i = 0; i < sizem; i++) {
      if (i < items1.size())
        mMap[items1[i][0]] += items1[i][1];
      if (i < items2.size())
        mMap[items2[i][0]] += items2[i][1];
    }
    vector<vector<int>> res;
    for (auto i = 1; i <= mMap.size(); i++) {
      if(mMap.find(i)!=mMap.end())
      res.push_back(vector<int>{i, mMap[i]});
    }
    return res;
  }
};
int main() {
  Solution s;
  vector<vector<int>> v1{{1, 1}, {2, 1}, {3, 3}};
  vector<vector<int>> v2{{1, 2}, {2, 2}, {4, 1},{5,2}};

  
  for(auto i : s.mergeSimilarItems(v1, v2)){
    cout<<i[0]<<" "<<i[1];
  }
}