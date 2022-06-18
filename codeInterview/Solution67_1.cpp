#include <bits/stdc++.h>

using namespace std;

class Automaton{
    string state = "start";
    unordered_map<string, vector<string>> table{
        //状态   输入：" "  ,  "+/- " , "number"  , "other"
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int getCol(int c){
        if (c == ' ')
            return 0;
        else if (c == '+' || c == '-')
            return 1;
        else if (isdigit(c))
            return 2;
        else
            return 3;
    }

public:
    int sign = 1;
    long long num = 0;

    void get(char c){
        state = table[state][getCol(c)];
        if (state == "signed"){
            sign = c == '+' ? 1 : -1;
        } else if (state == "in_number"){
            num = num * 10 + (c - '0');
            num = sign == 1 ? min((long long)INT32_MAX, num) : min(-(long long)INT32_MIN, num);
        }
    }
};

class Solution {
public:
    int strToInt(string str) {
        Automaton automaton;
        for (char c : str) {
            automaton.get(c);
        }
        return automaton.sign * automaton.num;
    }
};