#include <bits/stdc++.h>

using namespace std;

//约瑟夫环问题。题解做法
class Solution {
public:
    int lastRemaining(int n, int m) {
        int x = 0;
        for (int i = 2; i <= n; ++i) {
            x = (x + m) % i;
        }
        return x;
    }
};