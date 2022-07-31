#include <vector>
class Solution {
public:
    int maximumGroups(std::vector<int>& grades) {
        int s = grades.size();
        int delta = 1;
        int sum = 0;
        int step = 0;
        while(sum < s){
            sum += delta;
            delta ++;
            step ++;
        }
        if(sum == s)return step;
        else return step - 1;
    }
};