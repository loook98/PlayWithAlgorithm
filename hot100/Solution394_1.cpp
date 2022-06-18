#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //看了题解的答案
    string decodeString(string s) {
        string res;
        int multi = 0;
        stack<int> stack_multi;
        stack<string> stack_res;

        for (char c : s) {
            if (c == '['){
                stack_multi.push(multi);
                stack_res.push(res);
                multi = 0;
                res = "";
            } else if (c == ']'){
                string tmp;
                int cur_multi = stack_multi.top();
                stack_multi.pop();
                for (int i = 0; i < cur_multi; ++i) {
                    tmp.append(res);
                }
                res = stack_res.top() + tmp;
                stack_res.pop();
            } else if (c >= '0' && c <= '9'){
                multi = multi * 10 + (c - '0');
            } else{ //是字母
                res += c;
            }
        }
        return res;
    }
};

//结果错误
/*
class Solution {
public:
    bool isNum(char c) {
        return c >= '0' && c <= '9';
    }

    bool isWord(char c) {
        return c >= 'a' && c <= 'z';
    }

    string decodeString(string s) {
        stack<char> stack;
        string res, curStr;
        int i = 0;
        while (i < s.size()) {
            if (isNum(s[i])) {
                stack.push(s[i]);
                    i++;
                continue;
            }

            if (s[i] == '['){
                stack.push(s[i]);
                i++;
                continue;
            }

            if (!stack.empty() && s[i] == ']') {
                while (!isNum(stack.top()) && stack.top() != '[') {
                    char c = stack.top();
                    stack.pop();
                    curStr = c + curStr;
                }
                if (stack.top() == '[')
                    stack.pop();
                //重复的次数可能大于9，即不止一位
                int repeatNum = 0, len = 0;
                while (!stack.empty() && isNum(stack.top())){
                    char bit = stack.top();
                    stack.pop();
                    repeatNum += (bit - '0') * (int)pow(10, len); //len为当前这个数的权重
                    len++;
                }

                string tmp = curStr; //不保存curStr的话，要重复的时候就会出问题
                for (int j = 0; j < repeatNum - 1; ++j) {
                    curStr += tmp;
                }
                if (stack.empty()) {
                    res += curStr;
                    curStr = "";
                }
                ++i;
                continue;
            }

            if (!stack.empty() && isWord(s[i])) {
                stack.push(s[i]);
                ++i;
                continue;
            }

            if (stack.empty() && isWord(s[i])) {
                res += s[i];
                ++i;
                continue;
            }
        }
        return res;
    }
};*/
