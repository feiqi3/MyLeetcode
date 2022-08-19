#include "../header.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int r = nums.size()- 1;
        int l = 0;

        while (l < r) {
            int mid = l + (r - l)/2;
            if(nums[mid] < target){
                l = mid+1;
            }else if (nums[mid > target]) {
                r = mid;
            }else {
            return mid;
            }
        }
        return nums[l] == target ? l : -1;
    }
};

int main(){

}