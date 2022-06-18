#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = res * 26 + (columnTitle[i] - 'A' + 1);
        }
        return res;
    }
};