#include "../header.h"

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)return false;
        if(x / 10 == 0)return 1;
        char integer[10];
        int i = 0;
        while(x >0){
            integer[i] = x%10;
            x/=10;
            i++;
        }
        //bool flag = true;
        for (int j = 0;j< i / 2; j++) {
            if(integer[j] != integer[i-1-j])
            {
                return false;
            }
        }
        return true;
    }
};
int main(){
    Solution a;
    cout<<a.isPalindrome(124321);

}