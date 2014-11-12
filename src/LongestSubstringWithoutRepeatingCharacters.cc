/**
 * Given a string, find the length of the longest substring without repeating characters. 
 * For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
 * which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
**/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        int m[256];
        memset(m, -1, sizeof(m));
        int cs(0), ce(0);
        int curlen;
        for(; ce < s.length(); ce++){
            if(m[s[ce]] != -1 && cs <= m[s[ce]]){
                curlen = ce - cs;
                len = len > curlen ? len : curlen;
                cs = m[s[ce]] + 1;
            }
            m[s[ce]] = ce;
        }
        curlen = ce - cs;
        return len >  curlen ? len : curlen;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        map<char, int> m;
        map<char, int>::iterator itr;
        int cs(0), ce(0);
        int curlen;
        for(; ce < s.length(); ce++){
            itr = m.find(s[ce]);
            if(itr != m.end() && cs <= itr->second){
                curlen = ce - cs;
                len = len > curlen ? len : curlen;
                cs = itr->second + 1;
                itr->second = ce;
            }
            else{
                m[s[ce]] = ce;
            }
        }
        curlen = ce - cs;
        return len >  curlen ? len : curlen;
    }
};
