#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double calculateTax(vector<vector<int>> &brackets, int income) {
        double res = 0.0;
        int cnt = 0;
        for (int i = 0; i < brackets.size(); ++i) {
            if (income > brackets[i][0])
                cnt++;
        }

        for (int i = 0; i < brackets.size() && i <= cnt; ++i) {
            if (income < brackets[i][0]) {
                res += (i > 0 ? income - brackets[i-1][0] : income) * brackets[i][1] / 100.0;
            } else{
                res += (i > 0 ? brackets[i][0] - brackets[i-1][0] : brackets[i][0]) * brackets[i][1] / 100.0;
            }
        }

        return res;
    }
};