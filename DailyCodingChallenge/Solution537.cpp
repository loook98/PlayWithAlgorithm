#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        //num1 = a + bi; num2 = c + di;
        int a = 0, b = 0, c = 0, d = 0;
        calRealImaginary(num1, a, b);
        calRealImaginary(num2, c, d);
        int real = (a*c - b*d);
        int imag = (a*d + b*c);
        string ret = "";
        ret += to_string(real);
        ret += '+';
        ret += to_string(imag);
        ret += 'i';
        return ret;

    }

    void calRealImaginary(const string& num, int& real, int& imaginary){
        int index = 0, n = num.size();
        bool isNegative = false;
        if (num[index] == '-'){
            isNegative = true;
            index++;
        }
        while (index < n && num[index] != '+'){
            real = real * 10 + (num[index] - '0');
            index++;
        }
        if (isNegative)
            real = -real;

        index++; // 越过+
        if (num[index] == '-'){
            isNegative = true;
            index++;
        } else{
            isNegative = false;
        }
        while (index < n && num[index] != 'i'){
            imaginary = imaginary * 10 + (num[index] - '0');
            index++;
        }
        if (isNegative)
            imaginary = -imaginary;
    }
};