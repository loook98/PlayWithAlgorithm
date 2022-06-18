#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> res(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            res[i] = digits[i-1];
        }

        bool hasCarry = true;
        for (int i = n; i >= 0; --i) {
            if (hasCarry){
                int sum = res[i] + 1;
                res[i] = sum % 10;
                if (sum > 9)
                    hasCarry = true;
                else
                    hasCarry = false;
            } else
                break;
        }
        if (res[0] == 0)
            res.erase(res.begin());
        return res;
    }
};