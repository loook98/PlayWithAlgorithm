#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //1.先遍历一遍数组，记录数组中出现过的元素（用set）
        unordered_set<int> inNums;
        for (int &num: nums) {
            inNums.insert(num);
        }

        //2. 再遍历一边数组
        // 对于一个元素num，一直+1,直到在set中无法找到，更新「最长连续序列长度」
        // PS:对于num-1在set中存在的元素就不需要进行上述操作。（因为在num-1处已经算过num的了）
        int res = 0;
        for (int &num: nums) {
            if (!inNums.count(num-1)){
                int end = num + 1;
                while (inNums.count(end)){
                    end++;
                }

                res = max(res, end - num);
            }
        }

        return res;
    }
};