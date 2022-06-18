#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> leftBracket;

        int n = s.size();
        for (auto &c : s) {
            if (c == '(' || c =='[' || c == '{')
                leftBracket.push(c);
            else{
                if (c == ')'){
                    if (!leftBracket.empty() && leftBracket.top() == '(')
                        leftBracket.pop();
                    else
                        return false;
                } else if (c == ']'){
                    if (!leftBracket.empty() && leftBracket.top() == '[')
                        leftBracket.pop();
                    else
                        return false;
                } else{
                    if (!leftBracket.empty() && leftBracket.top() == '{')
                        leftBracket.pop();
                    else
                        return false;
                }
            }
        }

        return leftBracket.empty();
    }
};