#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> lParenthesisStack; //存放'('的下标
        stack<int> starStack; //存放'*'的下标

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*')
                starStack.push(i);
            if (s[i] == '(')
                lParenthesisStack.push(i);
            if (s[i] == ')'){
                if (!lParenthesisStack.empty())
                    lParenthesisStack.pop();
                else if (!starStack.empty())
                    starStack.pop();
                else
                    return false;
            }
        }

        //处理'('有剩余的情况
        if (!lParenthesisStack.empty()){
            if (lParenthesisStack.size() > starStack.size())
                return false;
            while (!lParenthesisStack.empty()){
                if (lParenthesisStack.top() < starStack.top()){
                    lParenthesisStack.pop();
                    starStack.pop();
                } else{
                    return false;
                }
            }
        }

        return true;
    }
};