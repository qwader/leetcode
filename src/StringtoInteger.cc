/**
 * Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front. 

**/

class Solution {
public:
    int atoi(const char *str) {
        if(!str) return 0;
        int flag = 0;
        int len = 0;
        long long ret = 0;
        while(*str){
            if(len == 0 && isspace(*str)){
                if(flag){
                    break;
                }
            }
            else if(*str == '-' && !flag){
                flag = -1;
            }
            else if(*str == '+' && !flag){
                flag = 1;
            }
            else if(isdigit(*str) && len < 11){
                ret = ret * 10 + *str - '0';
                len++;
            }
            else {
                break;
            }
            str++;
        };
        if(flag == 0){
            flag = 1;
        }
        if(flag * ret > INT_MAX){
            return INT_MAX;
        }
        if(flag * ret < INT_MIN){
            return INT_MIN;
        }
        return ret * flag;
    }
};
