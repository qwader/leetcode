/**
 * Determine whether an integer is a palindrome. Do this without extra space.
**/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int x1(x);
        int ret = 0;
        while(x1 > 0){
            ret = ret * 10 + x1 % 10;
            x1 /= 10;
        };
        return (ret == x);
    }
};
