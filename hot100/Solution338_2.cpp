#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        int highBit = 0;
        for (int i = 1; i <= n; ++i) {
            if ( (i & (i - 1)) == 0){
                highBit = i;
                res[i] = 1;
            } else{
                res[i] = res[i - highBit] + 1;
            }
        }
        return res;
    }
};