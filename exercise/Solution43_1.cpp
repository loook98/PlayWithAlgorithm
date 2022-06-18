#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string ret;
        int zeroNum = 0; //乘出的结果后面加的0的个数
        for (int i = num2.size() - 1; i >= 0; --i) {
            string multiRes = multiply(num1, num2[i]);
            for (int j = 0; j < zeroNum; ++j) {
                multiRes.push_back('0');
            }
            ret = add(ret, multiRes);
            zeroNum++;
        }

        if (ret[0] == '0')
            return "0";
        return ret;
    }

    //一个数乘以一位数，例如“123”*'2'
    string multiply(const string& num, char c){
        string ret;
        int carry = 0, cNum = c - '0';
        for (int i = num.size() - 1; i >= 0; --i) {
            int bitNum = num[i] - '0';
            int multiRes = cNum * bitNum;
            int temp = multiRes + carry;
            ret.insert(ret.begin(), ((temp % 10) + '0'));
            carry = temp / 10;
        }
        if (carry != 0)
            ret.insert(ret.begin(), (carry + '0'));
        return ret;
    }

    string add(const string& num1, const string& num2) {
        int carry = 0;
        int n1 = num1.size(), n2 = num2.size();
        string ret;
        int i1 = n1 - 1, i2 = n2 - 1;
        for ( ; i1 >= 0 && i2 >= 0; --i1,--i2) {
            int bit1 = num1[i1] - '0';
            int bit2 = num2[i2] - '0';
            int addRes = bit1 + bit2 + carry;
            ret.insert(ret.begin(), ((addRes % 10) + '0'));
            carry = addRes / 10;
        }

        if (i1 >= 0){
            for ( ; i1 >= 0; --i1) {
                int addRes = carry + num1[i1] - '0';
                ret.insert(ret.begin(), ((addRes % 10) + '0'));
                carry = addRes / 10;
            }
        } else if (i2 >= 0){
            for ( ; i2 >= 0; --i2) {
                int addRes = carry + num2[i2] - '0';
                ret.insert(ret.begin(), ((addRes % 10) + '0'));
                carry = addRes / 10;
            }
        }
        if (carry != 0)
            ret.insert(ret.begin(), (carry + '0'));
        return ret;
    }
};