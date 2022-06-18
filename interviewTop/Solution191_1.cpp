#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t bit = 1;
        int res = 0;
        while (n > 0) {
            if ((n & bit) == bit)
                ++res;
            n = n >> 1;
        }
        return res;
    }
};