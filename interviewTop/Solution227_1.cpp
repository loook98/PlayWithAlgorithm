#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int index = 0;

        if (n == 0)
            return 0;

        stack<int> nums; //存储运算操作数（+、-的）
        stack<char> ops; //存储+、-运算符。 （*、/运算符会直接算入结果）
        nums.push(parseInt(index, s));
        while (index < n) {
            if (s[index] == '*') {
                index++;
                int op2 = parseInt(index, s);
                int op1 = nums.top();
                nums.pop();

                //cout << "*res " << op1 * op2 << endl;
                nums.push(op1 * op2);
            } else if (s[index] == '/') {
                index++;
                int op2 = parseInt(index, s);
                int op1 = nums.top();
                nums.pop();

                //cout << "/res " << op1 / op2 << endl;
                nums.push(op1 / op2);
            } else if (s[index] == '+') {
                index++;
                int op2 = parseInt(index, s);

                nums.push(op2);
                ops.push('+');
            } else if (s[index] == '-'){
                index++;
                int op2 = parseInt(index, s);

                nums.push(op2);
                ops.push('-');
            }
        }

        //到此，表达式中的乘法已经计算完成。开始计算剩余的+、-法
        int ret = 0;
        while (!ops.empty()) {
            char op = ops.top();
            ops.pop();

            if (op == '+'){
                ret += nums.top();
                nums.pop();
            } else{
                ret -= nums.top();
                nums.pop();
            }
        }

        //此时nums中还剩一个
        ret += nums.top();
//        cout << ret << endl;
        return ret;
    }

    int parseInt(int &index, const string &s) {
        int n = s.size();
        while (index < n && s[index] == ' ')
            index++;

        int num = 0;
        while (index < n && (s[index] >= '0' && s[index] <= '9')) {
            num = num * 10 + (s[index] - '0');
            index++;
        }

        while (index < n && s[index] == ' ')
            index++;

       // cout << "parse " << num << endl;
        return num;
    }
};

/*
int main(){
    Solution().calculate("33423+1+2");
    return 0;
}
*/
