/**
 * Given a string S, find the longest palindromic substring in S. 
 * You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
**/

class Solution {
public:
    string longestPalindrome(string s) {

        int slen = s.length();
        int maxlen(1);
        int b(slen / 2);
        int start_index = slen / 2 - (slen + 1) % 2;
        check(s, start_index, maxlen, b);
        for(int i = 1; i <= slen / 2; i++){
            if((start_index - i + 1) * 2 > maxlen){
                check(s, start_index - i, maxlen, b);
            }
            if( ((slen - start_index - i - 1) * 2 + 1)> maxlen){
                check(s, start_index + i, maxlen, b);
            }
        }
        
        return s.substr(b, maxlen);
        
    }
    int check1(string& s, int index){
        int i = index, j = i + 1;
        for(; i >= 0 && j < s.length(); i--, j++){
            if(s[i] != s[j]){
                return j - i - 1;
            }
        }
        return j - i - 1;
    }
    int check2(string& s, int index){
        int i = index - 1, j = i + 2;
        for(; i >= 0 && j < s.length(); i--, j++){
            if(s[i] != s[j]){
                return j - i - 1;
            }
        }
        return j - i - 1;
    }
    void check(string& s, int index, int& max, int&b){
        int len = check1(s, index);
        if(max < len){
            max = len;
            b = index - len / 2 + 1;
        }
        len = check2(s, index);
        if(max < len){
            max = len;
            b = index - len / 2;
        }
    }
};
