#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minimizeResult(string expression) {
        int n = expression.size();
        int plus = 0; //+的索引
        for (int i = 0; i < n; ++i) {
            if (expression[i] == '+'){
                plus = i;
                break;
            }
        }

        if (plus == 0 || plus == n-1)
            return "";
        int minVal = INT32_MAX;
        int maxL = 0, maxR = 0;
        for (int left = plus - 1; left >= 0; --left) {
            for (int right = plus + 1; right < n; ++right) {
                int val = ((left - 1 >= 0 ? subStr2int(expression, 0, left -1) : 1) *
                           (subStr2int(expression, left, plus - 1) + subStr2int(expression, plus + 1, right)) *
                           (right + 1 < n ? subStr2int(expression, right + 1, n-1) : 1));
                cout << val << " " << minVal << endl;
                if (val < minVal){
                    minVal = val;
                    maxL = left;
                    maxR = right;
                }
            }
        }

        string res;
        for (int i = 0; i < n; ++i) {
            if (i == maxL)
                res.push_back('(');
            res.push_back(expression[i]);
            if (i == maxR)
                res.push_back(')');
        }
        return res;
    }

    //返回s[l...r]子串对应的数值
    int subStr2int(const string& s, int l, int r){
        return stoi(s.substr(l, r-l+1));
    }
};