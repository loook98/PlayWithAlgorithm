#include <bits/stdc++.h>

using namespace std;

//贪心
//当n>=5时，尽可能多地剪长度为3的绳子。剩下的绳子长度为4时，把绳子剪成2段长度为2的绳子。
class Solution {
public:
    int cuttingRope(int n) {
        if (n < 2)
            return 0;
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;

        int timesOf3 = n / 3;

        if (n - timesOf3 * 3 == 1)
            timesOf3--;

        int timesOf2 = (n - timesOf3 * 3) / 2;

        return (int)pow(3, timesOf3) * (int)pow(2,timesOf2);
    }
};