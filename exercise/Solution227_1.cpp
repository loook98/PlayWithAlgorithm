#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> values; //存放+ -法所需的元素。（* /法会在遍历中算出）
        stack<char> operators; //存储 + -运算符。 （* /法会在遍历中直接用掉）
        int index = 0;

        while (index < s.size()){
            while (s[index] == ' '){
                index++;
            }

            if (isdigit(s[index])){
                int num = readInt(s, index);
                values.push(num);
            } else if (s[index] == '+'){
                operators.push('+');
                index++;
            } else if (s[index] == '-'){
                operators.push('-');
                index++;
            } else if (s[index] == '*'){
                index++;
                //要跳过空格
                while (s[index] == ' ')
                    index++;
                int nextNum = readInt(s, index);
                int lastNum = values.top();
                values.pop();

                values.push(lastNum * nextNum);
            } else if (s[index] == '/'){ // s[index] == '/'
                index++;
                //要跳过空格
                while (s[index] == ' ')
                    index++;
                int nextNum = readInt(s, index);
                int lastNum = values.top();
                values.pop();

                values.push(lastNum / nextNum);
            }
        }

        //到此s中的* /法已经计算完毕，剩余的均为+ -法（没有优先级），数存在values栈中，运算符存在operators栈中
        //现在将剩余的+ -法完成计算
        int res = 0;
        while (!operators.empty()){
            char op = operators.top();
            operators.pop();
            int num = values.top();
            values.pop();
            if (op == '+')
                res += num;
            else
                res -= num;

        }
        res += values.top();
        values.pop();

        return res;
    }

    int readInt(string &s, int &i){
        int num = 0;
        while (i < s.size() && isdigit(s[i])){
            num = num * 10 + (s[i] - '0');
            i++;
        }

        return num;
    }
};