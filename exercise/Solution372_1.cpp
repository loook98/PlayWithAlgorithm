#include <bits/stdc++.h>

using namespace std;

//计算两个int的幂的过程没有使用快速幂
class Solution {
private:
    int base = 1337;
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty())
            return 1;
        int back = b.back();
        b.pop_back();

        int part1 = myPow(a, back);
        int part2 = myPow(superPow(a, b), 10);

        return (part1 * part2) % base;
    }

    int myPow(int a, int k){
        a %= base;
        int res = 1;
        for (int i = 0; i < k; ++i) {
            res *= a;
            res %= base;
        }
        return res;
    }
};