#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDigit(string number, char digit) {
        string res;
        for (int i = 0; i < number.size(); ++i) {
            if (number[i] == digit){
                string tmp = number;
                tmp.erase(i, 1);
                res = max(res, tmp);
            }
        }
        return res;
    }
};