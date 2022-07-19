#include "../header.h"
#include <string>
#include <vector>

class Solution {
public:
  vector<string> th = {"", "M", "MM", "MMM"};
  vector<string> hd = {"",  "C",  "CC",  "CCC",  "CD",
                             "D", "DC", "DCC", "DCCC", "CM"};
  vector<string> tem = {"",  "X",  "XX",  "XXX",  "XL",
                              "L", "LX", "LXX", "LXXX", "XC"};
  vector<string> nu = {"",  "I",  "II",  "III",  "IV",
                              "V", "VI", "VII", "VIII", "IX"};
  string intToRoman(int num) {
    int k = num / 1000;
    int h = num % 1000 / 100;
    int t = num % 100 / 10;
    int n = num % 10;
    return th[k]+hd[h]+tem[t]+nu[n];
  }
};

int main()
{

    cout<<Solution().intToRoman(1994);
}