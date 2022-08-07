#include "../header.h"
#include <map>
#include <set>

class Solution {
public:
  string decodeMessage(string key, string message) {
    int pos = 0;
    map<char, char> mSet;
    for (auto s : key) {
      if (s == ' ')
        continue;
      if (mSet.size() <= 26 && mSet.find(s) == mSet.end()) {
        mSet[s] = pos + 'a';
        pos++;
      } else {
        continue;
      }
    }
    string res;
    res.reserve(message.size()*sizeof(char) + 10);
    for (int i = 0; i < message.size(); i++) {
      if (message[i] == ' ') {
        res[i] = ' ';
        continue;
      }
      res[i] = mSet[message[i]];
    }
    return res;
  }
};
int main() {
  Solution s;
  cout << s.decodeMessage("the quick brown fox jumps over the lazy dog",
                          "vkbs bs t suepuv");
}
