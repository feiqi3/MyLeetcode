#include "../header.h"
/*
    算出两个数组  
    从右边向左边的最小值数组minR
    从左边向右边的最大值数组maxR   
    如果一个区间的最大值
    小于等于下一个区间的最小值
    那么这个区间一定递增  

*/
class Solution {
public:
  int maxChunksToSorted(vector<int> &arr) {
        vector<int> leftMax(arr.size(), 0);
        vector<int> rightMin(arr.size(), 0);
        int s = arr.size();
        int maxL = arr[0];
        int minR = arr[s - 1];
        leftMax[0] = arr[0];
        rightMin[s - 1] = arr[s - 1];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > maxL) {
                maxL = arr[i];
            }
            leftMax[i] = maxL;
            int rI = s - 1 - i;
            if (rI >= 0 && arr[rI] < minR) {
                minR = arr[rI];
            }
            rightMin[rI] = minR;
        }
        int res = 1;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (leftMax[i] <= rightMin[i+1]) {
                res +=1;
            }
        }
        return res;
  }
};