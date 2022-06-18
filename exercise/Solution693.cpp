#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int x = n ^ (n >> 1);
        return (x & (x + 1)) == 0;
    }
};