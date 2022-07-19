#include "../header.h"
#include <string>
#include <unordered_map>
class Solution {
public:
  int romanToInt(string s) {
    unordered_map<char, int> roman2int{{'N', 0},   {'M', 1000}, {'D', 500},
                                       {'C', 100}, {'L', 50},   {'X', 10},
                                       {'V', 5},   {'I', 1}};
    int last = 0;
    int res = 0;
    for (auto i = s.rbegin(); i != s.rend(); i++) {
      int num = roman2int[*i];
      if (num >= last) {
        res += num;
      } else if (num < last) {
        res -= num;
      }
      last = num;
    }
    return res;
  }
};
int main()
{
    cout<<Solution().romanToInt("MCMXCIV");
}