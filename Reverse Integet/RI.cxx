#define  __INT_MIN -2147483648
#define  __INT_MAX 2147483648-1
#include<iosfwd>
class Solution {
public:
    int reverse(int x) {
        long n = 0;
        while(x > 0)
        {
            n = x % 10 + n*10;
            x = x / 10;
        }
        
        if(n < __INT_MIN || n > __INT_MAX)
        return 0;
        else 
        return n;
    }
};