#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string res;
        while (num > 0){
            if (num >= 1000){
                int M = num / 1000;
                for (int i = 0; i < M; ++i) {
                    res.push_back('M');
                }
                num %= 1000;
            } else if (num >= 100){
                if (num >= 900){
                    res += "CM";
                    num -= 900;
                } else if (num >= 500){
                    res += "D";
                    num -= 500;
                } else if (num >= 400){
                    res += "CD";
                    num -= 400;
                } else{
                    int C = num / 100;
                    for (int i = 0; i < C; ++i) {
                        res += "C";
                    }
                    num %= 100;
                }
            }else if(num >= 10){
                if (num >= 90){
                    res += "XC";
                    num -= 90;
                } else if (num >= 50){
                    res += "L";
                    num -= 50;
                } else if (num >= 40){
                    res += "XL";
                    num -= 40;
                } else{
                    int X = num / 10;
                    for (int i = 0; i < X; ++i) {
                        res += "X";
                    }
                    num %= 10;
                }
            } else{ //num >= 1
                if (num >= 9){
                    res += "IX";
                    num -= 9;
                } else if (num >= 5){
                    res += "V";
                    num -= 5;
                } else if (num >= 4){
                    res += "IV";
                    num -= 4;
                } else{
                    int I = num;
                    for (int i = 0; i < I; ++i) {
                        res += "I";
                    }
                    num %= 1;
                }
            }
        }

        return res;
    }
};

