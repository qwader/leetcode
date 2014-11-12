/**
 * Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
**/
class Solution {
    int r2i(char c){
        switch(c) {
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'I':
                return 1;
            case 'L':
                return 50;
            case 'M':
                return 1000;
            case 'V':
                return 5;
            case 'X':
                return 10;
            default:
                return 0;
        }
    }
public:
    int romanToInt(string s) {
        if(s.length() == 0){
            return 0;
        }

        int ret = 0;
        const char *str = s.c_str();
        int len = s.length();
        int i = 0;
        int cur, next;
        cur = r2i(s[0]);
        ++i;
        while(i < len){
            next = r2i(s[i]);
            if(cur < next){
                ret += next - cur;
                cur = r2i(s[++i]);
            }
            else{
                ret += cur;
                cur = next;
            }
            ++i;
        }
        ret += cur;
        return ret;
    }
};
