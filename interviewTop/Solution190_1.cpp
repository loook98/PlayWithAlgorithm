#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        uint32_t left = 2147483648, right = 1;
        for (int i = 0; i < 32; ++i) { ;
            if ((n & right) > 0)
                res |= left;

            left = left >> 1;
            right = right << 1;
        }
        return res;
    }
};