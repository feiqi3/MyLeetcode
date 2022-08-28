#include "../header.h"
#include <string_view>
class Solution {
public:
  string removeStars(string s) {
    int le = 0;
    int ri = 0;
    for (; ri < s.size(); ri++) {
      if (s[ri] == '*') {
        le--;
      } else {
        s[le] = s[ri];
        le++;
      }
    }
    return s.substr(0,le);
  }
};

int main() {
  string re = "wdp**yy**gkp**n***d*k*nm*l**ze**sq*p";
  Solution s;
  s.removeStars(re);
}