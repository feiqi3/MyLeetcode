#include "../header.h"
#include <iostream>
#include <ostream>
#include <vector>

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int res = 0;
        int energySum = 0;
        for (int i = 0; i < energy.size(); i++) {
            energySum +=energy[i];
        }     
        res +=(energySum + 1 - initialEnergy) > 0 ? (energySum + 1 - initialEnergy) : 0;
        std::cout<<res;
        int flag = 0;
        int tmp_exp = initialExperience;
        if(experience[0] >= initialExperience){
            int tmp = experience[0] + 1 - initialExperience;
            res+= tmp;
            tmp_exp = initialExperience + tmp;

        }
        for (int i = 1; i< experience.size(); i++) {
            tmp_exp += experience[i -1];
            res += (experience[i] + 1 - tmp_exp) > 0 ? (experience[i] + 1 - tmp_exp) : 0;
        }
        return res;
    }
};
int main(){
    std::vector<int> a{1,4,3,2};
    std::vector<int> b{2,6,3,1};
    Solution s;
    s.minNumberOfHours(5,3, a, b);
}