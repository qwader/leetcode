/**
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

**/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> m;
        map<int, int>::iterator itr_map;
        int index;
        vector<int> ret;
        for(index = 0; index < numbers.size(); index++){
            itr_map = m.find(numbers[index]);
            if(itr_map != m.end()){
                itr_map->second = index;
            }
            else {
                m.insert(pair<int, int>(numbers[index], index));
            }
        }
        for(index = 0; index < numbers.size(); index++){
            int need = target - numbers[index];
            itr_map = m.find(need);
            if(itr_map == m.end()){
                continue;
            }
            if(itr_map->second != index){
                ret.push_back(index + 1);
                ret.push_back(itr_map->second + 1);
                return ret;
            }
        }
        ret.push_back(-1);
        ret.push_back(-1);
        return ret;
    }
};
