#include <bits/stdc++.h>

using namespace std;

//6100. 统计放置房子的方式数
//有问题
class Solution {
public:
    int MOD = 1000000007;

    int countHousePlacements(int n) {
        vector<long long> put(n + 1); //在一侧放i个房子的方法数

        put[0] = 1;
        put[1] = n;
        if (n > 1)
            put[n] = 0;

        for (int i = 2; i < n; ++i) {
            if (n < 2 * i - 1)
                put[i] = 0;
            else if (n == 2 * i - 1)
                put[i] = 1;
            else
                put[i] = C(n - i + 1, i) % MOD;
        }

        int res = 0;
        for (int i = 0; i <= n; ++i) {
            long long val = 0;
            for (int j = i; j <= n; ++j) {
                long long multiply = (put[i] * put[j]) % MOD;
                val = (val + multiply) % MOD;
                if (j != i)
                    val = (val + multiply) % MOD;
            }
            res = (res + val) % MOD;
        }

        return res;
    }

    long long C(int n, int m) {
        long long a = 1, b = 1;
        //for (int i = n; i > n - m; --i) a *= i;
        for (int i = n; i > n - m; --i) a = (a * i) % MOD;
        //for (int i = m; i >= 1; i--) b *= i;
        for (int i = m; i >= 1; i--) b = (b * i) % MOD;
        return a / b;
    }
};