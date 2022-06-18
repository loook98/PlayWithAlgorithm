#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumNums(int n) {
        int ret = 1;
        n > 1 && (ret = n + sumNums(n-1));
        return ret;
    }
};