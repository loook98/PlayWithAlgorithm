#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool isPositive = true;
        if (x < 0)
            isPositive = false;

        unsigned int absX;
        if (x == INT32_MIN)
            absX = 2147483647u + 1u;
        else
            absX= abs(x);

        string str_reveredAbsX;
        while (absX > 0){
            int temp = absX % 10u;
            str_reveredAbsX += to_string(temp);
            absX /= 10;
        }

        //for test
        //cout << str_reveredAbsX << endl;
        //

        int n = str_reveredAbsX.size();
        unsigned int reversedAbsX = 0;
        int exponent = 0;
        for (int i = n-1; i >= 0; --i) {
            if (exponent == 9 && (str_reveredAbsX[i] - '0' > 2))
                return 0;
            reversedAbsX += (str_reveredAbsX[i] - '0') * ((unsigned int)pow(10,exponent));
            exponent++;
        }

        //for test
        //cout << "翻转后："<< reversedAbsX << endl;
        //

        int ret = -1;
        if (isPositive){
            if (reversedAbsX > 2147483647u)
                return 0;
            else
                ret = reversedAbsX;
        } else{
            if (reversedAbsX > 2147483647u + 1u)
                return 0;
            else
                ret = 0 - reversedAbsX;
        }
        return ret;
    }
};