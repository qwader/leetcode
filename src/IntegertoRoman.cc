/**
 * Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
**/

class Solution {

#define numofarr(X)  sizeof(X) / sizeof(X[0])

public:
    string intToRoman(int num) {
        int a[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        char* b[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ret;
        
        for(int i = 0; i < numofarr(a); i++){
            while(num >= a[i]){
                ret += b[i];
                num -= a[i];
            };
        }
        return ret;
    }
};
