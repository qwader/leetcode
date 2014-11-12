/**
 * Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321 

**/

class Solution {
public:
    int reverse(int x) {
        int flag = x < 0 ? -1 : 1;
        x *= flag;
        int ret = 0;
        while(x > 0){
            ret = ret * 10 + x % 10;
            x /= 10;
        };
        return ret * flag;
    }
};
