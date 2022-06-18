#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(31, 0); //记录数组中每个数的第[30...0]位出现的总数

        for (int num : nums) {
            int bit = 1;
            for (int i = 0; i < 31; ++i) {
                if ((num & bit) != 0)
                    bits[i]++;
                bit <<= 1;
            }
        }

        int res = 0;
        for (int i = 0; i < 31; ++i) {
            if (bits[i] % 3 != 0)
                res += (int) pow(2, i);
        }

        return res;
    }
};