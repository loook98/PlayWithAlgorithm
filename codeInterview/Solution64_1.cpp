#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumNums(int n) {
        int ret = 1;
        n > 1 && (ret = sumNums(n-1)+ n);
        return ret;
    }
};