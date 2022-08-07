#include "../header.h"
#include <vector>
class Solution {
public:
  int arithmeticTriplets(vector<int> &nums, int diff) {
    std::vector<int> a;
    for (int i = 1; i < nums.size(); i++) {
      a.push_back(nums[i] - nums[i - 1]);
    }
    int res = 0;
    for (int i = 0; i < a.size() - 3; i++) {
        if(a[i] != diff)continue;;
        int flag = 0;
        int turn = 1;
        int tmp_sum = 0;
        for (int j = i+1; j <a.size() - 1; j++) {
            tmp_sum+=a[j];
            if(tmp_sum == diff){
                turn ++;
                tmp_sum = 0;
            }else {
                continue;
            }
            if(turn == 3){
                flag = 1;
                break;
            }
        }
        res+=flag;
    }
    return res;
  }
};
