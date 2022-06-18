#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int bits = 1; //按数的位数划分组，bits表示当前组中数的位数
        while (true) {
            int numInGroup = countNums(bits);

            if (n >= (long long)numInGroup * bits){
                n -= numInGroup * bits;
                bits++;
                continue;
            } else{
                return findNthBit(bits, n);
            }
        }
    }

    int  findNthBit(int bits, int n){
        int nthNum = n / bits;   //对应的第n位为第nthNum个数中的(从0开始)
        int remain = n % bits;   //对应数的第几位(从0开始)

        int groupStart = beginNumber(bits);
        int num = groupStart + nthNum;

        string s = to_string(num);
        return s[remain] - '0';
    }

    int countNums(int bits){
        if (bits == 1)
            return 10;

        return (int) pow(10, bits - 1) * 9;
    }

    int beginNumber(int bits){
        if (bits == 1)
            return 0;

        return (int) pow(10, bits - 1);
    }
};