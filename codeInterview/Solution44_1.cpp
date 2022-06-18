#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int digit = 1;
        while (true){
            int count = countNumsOfDigit(digit);
            if ((long long)n < (long long)count * (long long)digit){//找的该位是当前digit位数中的
                int number = beginNumber(digit) + n / digit;
                int indexFromRight = digit - n % digit;
                for (int i = 1; i < indexFromRight; ++i) {
                    number /= 10;
                }
                return number%10;
            }
            n -= count * digit;
            digit++;
        }
        return -1;
    }
    //计算digit位的数共有多少个
    int countNumsOfDigit(int digit){
        if (digit == 1)
            return 10;
        return 9*static_cast<int>(pow(10, digit-1));
    }
    //计算digit位数开始的数
    int beginNumber(int digit){
        if(digit == 1)
            return 0;
        return static_cast<int>(pow(10, digit - 1));
    }
};