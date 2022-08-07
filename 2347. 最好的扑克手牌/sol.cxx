#include "../header.h"
class Solution {
public:
  string bestHand(vector<int> &ranks,vector<char> &suits) {
    char last = suits[0];
    int flag = 1;
    for (auto i = 1; i < suits.size(); i++) {
      if (suits[i] != last) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      return "Flush";
    }
    sort(ranks.begin(), ranks.end());
    int max_len = -1;
    int tmp_len = 1;
    for (int i = 1; i < ranks.size(); i++) {
      if (ranks[i] == ranks[i - 1]) {
        tmp_len++;
        max_len = max(tmp_len, max_len);
      } else {
        tmp_len = 1;
      }
    }
    if (max_len == 2) {
    return "Pair";
    }else if (max_len >= 3) {
    return "Three of a Kind";
    }else {
    return "High Card";
    }
  }
};
int main(){
    Solution s;
    std::vector<int> a{10,10,2,12,9};
    std::vector<char> b{'a','b','c','a','d'};

    cout<<s.bestHand(a, b);
}