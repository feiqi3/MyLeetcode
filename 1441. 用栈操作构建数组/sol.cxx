#include "../header.h"
#include <vector>

class Solution {
public:
  string push = "Push";
  string pop = "Pop";
  vector<string> buildArray(vector<int> &target, int n) {
    vector<string> res;
    int s = target.size();
    
    for (int i = 1,it = 0; it < s;it++) {
        if(target[it] == i){
            res.push_back(push);
            i++;
        }
        if(target[it] > i){
            vector<string> tmp;
            for (int j = i;  j < target[it]; j++) {
                tmp.push_back(pop);
                res.push_back(push);
            }
            res.insert(res.end(), tmp.begin(),tmp.end());
            res.push_back(push);
            i = target[it]+1;
        }
    }
    return res;
  }
};

/*
[1,3]
3
[1,2,3]
3
[1,2]
4
[2,3,4]
4
*/

int main() {
  Solution s;
  std::vector<int> a{2, 3,4};
  s.buildArray(a, 4);
}