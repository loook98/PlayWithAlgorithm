#include <bits/stdc++.h>

using namespace std;

//有问题
//这种解法不能解决()(()()这种情况
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n == 0 || n == 1)
            return 0;

        int res = 0, i = 0;
        int _res = 0, leftCnt = 0;
        while (i < n){
            if (s[i] == ')'){
                if (leftCnt == 0){
                    res = max(res, _res);
                    _res = 0;
                }
                else{
                    leftCnt--;
                    _res += 2;
                }
            } else{ // '('
                leftCnt++;
            }
            i++;
        }
        if (leftCnt == 0)
            res = max(res, _res);

        return res;
    }
};