#include <bits/stdc++.h>

using namespace std;

class AutoMachine {
private:
    string state = "start";

    unordered_map<string, vector<string>> table{
            //状态 |  输入(space, sign, num, other)
            {"start", {"start", "sign", "num", "end"}},
            {"sign",  {"end",   "end",  "num", "end"}},
            {"num",   {"end",   "end",  "num", "end"}},
            {"end",   {"end",   "end",  "end", "end"}}
    };

    int getColumnNum(char c) {
        if (c == ' ')
            return 0;
        else if (c == '+' | c == '-')
            return 1;
        else if (c >= '0' && c <= '9')
            return 2;
        else
            return 3;
    }

public:
    int sign = 1;
    int long long num = 0;

    void input(char c) {
        state = table[state][getColumnNum(c)];
        if (state == "sign")
            sign = c == '+' ? 1 : -1;
        else if (state == "num")
            num = sign == 1 ? min((long long)INT32_MAX, (num * 10 + (c - '0'))) :
                              min((long long)INT32_MAX+1, (num * 10 + (c - '0')));
    }
};

class Solution {
public:
    int strToInt(string str) {
        AutoMachine am;
        for (char c : str) {
            am.input(c);
        }

        return am.sign * am.num;
    }
};