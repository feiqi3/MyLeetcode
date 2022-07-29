#include "../header.h"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <limits>
#include <vector>
typedef vector<int> vec2;
vec2 operator-(vec2 &a,vec2&b){
   return vec2{a[0] - b[0], a[1] - b[1]};
}
class Solution {
public:
  float len(const vec2 &a) { return a[0] * a[0] + a[1] * a[1]; }
  bool validSquare(vector<int> &a, vector<int> &b, vector<int> &c,
                   vector<int> &d) {
      vector<float> lens{len(b-a),len(c-b),len(d-c),len(d-a),len(d-b),len(a-c)};
      std::sort(lens.begin(), lens.end());
      if(lens[5] == lens[0])return false;
      return lens[0] == lens[1] && lens[3] == lens[1] && lens[5] == lens[4];
  }
};
int main(){
    Solution s;
    vec2 a{1,1};
    vec2 b{5,3};
    vec2 c{3,5};
    vec2 d{7,7};
    s.validSquare(a,b,c,d);
}