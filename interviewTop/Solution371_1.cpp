#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //递归
    int getSum(int a, int b) {
        int xorVal = a ^ b; //无进位加
        int andVal = a & b; //左移一位后为进的位
        andVal  = (unsigned int )andVal << 1; //对负数进行左移，LeetCode编译器会报错

        if (andVal == 0)
            return xorVal;
        return getSum(xorVal, andVal);
    }
};