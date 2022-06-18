#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorRes = x ^ y;
        int res = 0, flag = 1;
        while (flag){
            if (xorRes & flag)
                ++res;
            flag = flag << 1;
        }
        return res;
    }
};
