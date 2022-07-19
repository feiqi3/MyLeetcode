
#include "../header.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <stdint.h>
using namespace std;
class Solution {
public:
  int myAtoi(string s) {
    char sign = 1;
    long long res = 0;
    auto itor = s.begin();
    //处理前导空格
    while (1) {
      auto tmp = *itor;
      if (tmp == ' ') {
        itor++;
      } else if (tmp >= '0' && tmp <= '9') {
        break;
      } else if (tmp <= 'z' && tmp >= 'a') {
        return 0;
      } else {
        break;
      }
    }
    if (*(itor) == '+') {
      sign = 1;
      itor++;
    } else if (*(itor) == '-') {
      sign = -1;
      itor++;
    }
    //处理0与其他情况
    while (1) {
      if (*itor == '0') {
        itor++;
      } else if (*itor < '0' || *itor > '9') {
        return 0;
      } else {
        break;
      }
    }
    int bit = 1;
    for (auto &i = itor; *i >= '0' && *i <= '9'; i++, bit++) {
      if (bit > 10) {
        if (sign == 1)
          return INT_MAX;
        else
          return INT_MIN;
      }
      res *= 10;
      res += *i - '0';
      std::cout<<res<<"\n";
    }
        
    res *= sign;

    if (res <= INT_MIN) {
      return INT_MIN;
    }
    if (res >= INT_MAX) {
      return INT_MAX;
    }
    return res;
  }
};

int main() {
  Solution a;
  cout << a.myAtoi("2147483648");
}