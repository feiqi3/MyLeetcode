#include "../header.h"
#include <limits>
#include <map>
#include <vector>
class Solution {
public:
  std::map<long, long> score;
  int edgeScore(vector<int> &edges) {
    for (int i = 0; i < edges.size(); i++) {
        score[edges[i]] += i;
    }
    long long max = std::numeric_limits<int>::min();
    int res;
    for(auto& i : score){
        if(i.second > max){
            max = i.second;
            res = i.first;
        }else if (i.second == max) {
            res = min((long)res,i.first);
        }
    }
    return res;
  }
};
int main(){}