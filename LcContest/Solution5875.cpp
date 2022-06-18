#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for (auto str: operations) {
            if (str[1] == '+')
                res++;
            else
                res--;
        }
        return res;
    }
};