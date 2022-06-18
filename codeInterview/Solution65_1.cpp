#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int add(int a, int b) {
        while (b != 0){
            int carry = (unsigned int) (a & b) << 1; //进位的部分,转为无符号是因为leetcode编译器的对附属移位会出错
            a ^= b; //不进位的部分
            b = carry;
        }
        return a;
    }
};

