#include "../header.h"
#include <iostream>
#include <limits>
#include <map>
class Solution {
public:
  map<char, unsigned char> m;
  char repeatedCharacter(string s) {
    int min_ = numeric_limits<int>::max();
    for (int i = 0; i < s.size(); i++) {
      if (m.find(s[i]) != m.end()) {
        if (i < min_) {
          min_ = i;
        }
      } else {
        m[s[i]] = 1;
      }
    }
    return s[min_];
  }
};

int main() {
  Solution s;
  std::cout << s.repeatedCharacter("absasd");
}