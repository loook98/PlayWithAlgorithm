#include <bits/stdc++.h>

using namespace std;

//计算两个int的幂的过程使用快速幂
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
        if (k == 0)
            return 1;
        a %= base;

        if ((k & 1) == 1){ //k为基数
            return (a * myPow(a, k-1)) % base;
        } else{
            int sub = myPow(a, k/2);
            return (sub * sub) % base;
        }
    }
};