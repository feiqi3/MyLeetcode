#include "../header.h"
#include <vector>

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax(height.size(), 0);
        vector<int> rightMax(height.size(), 0);

        int s = height.size();

        int maxL = height[0];

        int maxR = height[s - 1];
        leftMax[0] = height[0];
        rightMax[s - 1] = height[s - 1];

        for (int i = 1; i < height.size(); i++) {
            if (height[i] > maxL) {
                maxL = height[i];
            }
            leftMax[i] = maxL;

            int rI = s - 1 - i;
            if (rI >= 0 && height[rI] > maxR) {
                maxR = height[rI];
            }
            rightMax[rI] = maxR;
        }
        int nonZeroI;
        for (int i = 0; i < height.size(); i++) {
            if (height[i] != 0) {
                nonZeroI = i;
                break;
            }
        }
        int res = 0;
        for (; nonZeroI < height.size(); nonZeroI++) {
            int tmp = min(leftMax[nonZeroI], rightMax[nonZeroI]) - height[nonZeroI];
            res += tmp > 0 ? tmp : 0;
        }
        return res;
    }
};
