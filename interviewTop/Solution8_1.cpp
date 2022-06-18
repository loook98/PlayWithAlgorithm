#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        if (n == 0)
            return 0;
        bool sign = true;//数值的符号，true为+，false为-。
        int l = 0, r = 0;
        while (l < n && (s[l] == ' ')){
            l++;
        }

        if ( l < n && s[l] == '-') {
            sign = false;
            l++;
        } else if (l < n && s[l] == '+'){
            l++;
        }

        while (l < n && s[l] == '0')
            l++;

        r = l;
        while (r < n && (s[r] >= '0' && s[r] <= '9'))
            r++;

        if (r - l == 0)
            return 0;

        if (r - l > 10){
            if (sign)
                return INT32_MAX;
            else
                return INT32_MIN;
        }

        long long num = 0;
        while (l < r){
            long temp = s[l] - '0';
            //num += (num * 10) + (s[l] - '0');
            num = (num * 10) + temp;
            l++;
        }

        if (!sign)
            num = -num;

        if (num > INT32_MAX)
            return INT32_MAX;
        else if (num < INT32_MIN)
            return INT32_MIN;

        return num;
    }
};