#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0)
            return 0;

        vector<int> ugly(n);
        ugly[0] = 1;

        int nextUglyIndex = 1;      //存放下一个丑数的索引
        int T2 = 0, T3 = 0, T5 = 0; //T2位置以前的数乘以2均小于等于当前最大丑数，T3 T5类似

        while (nextUglyIndex < n) {
            //计算当前的丑数
            int newUgly = min(ugly[T2] * 2, min(ugly[T3] * 3, ugly[T5] * 5));
            ugly[nextUglyIndex++] = newUgly;

            //更新T2,T3,T5
            while (ugly[T2] * 2 <= ugly[nextUglyIndex - 1])
                T2++;
            while (ugly[T3] * 3 <= ugly[nextUglyIndex - 1])
                T3++;
            while (ugly[T5] * 5 <= ugly[nextUglyIndex - 1])
                T5++;
        }

        return ugly[n-1];
    }
};