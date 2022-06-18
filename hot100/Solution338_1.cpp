#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //O(nlogn)的时间复杂度
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            int count = 0;
            for (int j = 0; j <= 16; ++j) {
                if (i & (static_cast<int>(pow(2, j))))
                    count++;
            }
            res[i] = count;
        }
        return res;
    }
};