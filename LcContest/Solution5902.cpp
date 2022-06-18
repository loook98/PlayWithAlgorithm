#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isNum(char c){
        return c >= '0' && c <= '9';
    }
    bool areNumbersAscending(string s) {
        int n = s.size();
        int lastNum = 0, curNum = 0;
        for (int i = 0; i < n; ) {
            if (!isNum(s[i])){
                i++;
                continue;
            }
            curNum = 0;
            while (i < n && isNum(s[i])){
                curNum = curNum * 10 + (s[i] - '0');
                i++;
            }
            //cout << lastNum << " " << curNum <<endl;
            if (curNum <= lastNum)
                return false;
            lastNum = curNum;
        }
        return true;
    }
};