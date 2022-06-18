#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int carryNum = 0;
        int n1 = num1.size(), n2 = num2.size();
        vector<char> result(max(n1, n2) + 1);

        int i1 = n1 - 1, i2 = n2 - 1;
        int i = result.size() - 1;
        while (i1 >= 0 && i2 >= 0){
            int v1 = num1[i1] - '0';
            int v2 = num2[i2] - '0';
            int temp = v1 + v2 + carryNum;
            result[i] = (temp % 10) + '0';
            carryNum = temp / 10;

            i1--;
            i2--;
            i--;
        }

        while (i1 >= 0){
            int v1 = num1[i1] - '0';
            int temp = v1 + carryNum;
            result[i] = (temp % 10) + '0';
            carryNum = temp / 10;

            i1--;
            i--;
        }
        while (i2 >= 0){
            int v2 = num2[i2] - '0';
            int temp = v2 + carryNum;
            result[i] = (temp % 10) + '0';
            carryNum = temp / 10;

            i2--;
            i--;
        }
        //处理最后可能进的一位
        if (carryNum != 0)
            result[0] = carryNum + '0';


        if (carryNum == 0)
            return string(result.begin() + 1, result.end());
        else
            return string(result.begin(), result.end());
    }
};