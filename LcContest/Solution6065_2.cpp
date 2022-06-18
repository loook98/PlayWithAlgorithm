#include <bits/stdc++.h>

using namespace std;

//6065. 按位与结果大于零的最长组合
//几个数相与的结果要>0,则这几个数必有一位都为1.
//故统计每一位在数组中的数中出现1的次数，出现1次数最多的那一位的「1的出现次数」就是答案，
class Solution {
public:
    int largestCombination(vector<int> &candidates) {
        int res = 0;

        int bit = 1;
        for (int i = 0; i < 31; ++i) {
            int cnt = 0;
            for (int &candidate : candidates) {
                if ((candidate & bit) != 0)
                    cnt++;
            }
            res = max(res, cnt);
            bit <<= 1;
        }

        return res;
    }
};