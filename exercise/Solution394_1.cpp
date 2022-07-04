#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<string> stk;

        int index = 0;
        while (index < n){
            if (isdigit(s[index])){
                string k;
                while (index < n && isdigit(s[index])){
                    k.push_back(s[index]);
                    index++;
                }
                stk.push(k);
            } else if (islower(s[index])){
                string str;
                while (index < n && islower(s[index])){
                    str.push_back(s[index]);
                    index++;
                }
                stk.push(str);
            } else if (s[index] == '['){
                stk.push("[");
                index++;
            } else{ // == ']'
                stack<string> tempStk; //临时存储[]内的string
                while (!stk.empty() && stk.top() != "["){
                    tempStk.push(stk.top());
                    stk.pop();
                }
                string tempStr; //根据tempStk生成的str
                while (!tempStk.empty()){
                    tempStr += tempStk.top();
                    tempStk.pop();
                }
                //弹出"["
                stk.pop();
                //取出重复的次数
                string numStr = stk.top();
                stk.pop();
                int num = stoi(numStr);

                //生成新的字符串压入栈中
                string newStr;
                for (int i = 0; i < num; ++i) {
                    newStr += tempStr;
                }
                stk.push(newStr);

                index++; //不要忘了
            }
        }

        //取出栈中所有字符串连成res.因为是逆序的，所以要放入一个临时栈中再取出
        string res;
        stack<string> tempStk;
        while (!stk.empty()){
            tempStk.push(stk.top());
            stk.pop();
        }
        while (!tempStk.empty()){
            res += tempStk.top();
            tempStk.pop();
        }

        return res;
    }
};