#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int ret = 0;
        //从最低位到最高位计算ret该位的值
        int bit = 1;
        for (int i = 0; i < 32; ++i) {
            int bitSum = 0;
            for (const int num : nums) {
                if ((num & bit) != 0)
                    bitSum++;
            }
            if (bitSum % 3 != 0)
                ret |= bit;

            if (i != 31)
                bit = bit << 1;
        }
        return ret;
    }
};