#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //循环
    int getSum(int a, int b) {
        int xorVal = a, andVal = b, temp;
        do {
            temp = xorVal ^ andVal;
            andVal = xorVal & andVal;
            andVal = (unsigned int ) andVal << 1;
            xorVal = temp;

        } while (andVal != 0);
        return xorVal;
    }
};