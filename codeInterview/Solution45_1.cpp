#include <bits/stdc++.h>

using namespace std;
//输入数组长度超过16就报错heap-buffer-overflow。
//是sort()中报错的。
class Solution {
public:
    static bool _comp(const string& s1, const string& s2){
        int i = 0;
        int n1 = s1.size(), n2 = s2.size();
        while (i < n1 && i < n2){
            if (s1[i] < s2[i])
                return true;
            else if (s1[i] > s2[i])
                return false;
            i++;
        }
        //处理两数相等或公共部分相等
        if (n1 == n2)
            return true;
        else if (n1 > n2){
            return _comp(s1.substr(i, n1-i),s2);
        } else{
            return _comp(s1, s2.substr(i, n2- i));
        }
    }

    static bool comp(const int num1, const int num2){
        if (num1 == 0)
            return true;
        else if (num2 == 0)
            return false;
        return _comp(to_string(num1), to_string(num2));
    }

    string minNumber(vector<int>& nums) {
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }
        sort(strNums.begin(), strNums.end(), _comp);

        string res;
        for (string str : strNums) {
            res += str;
        }
        return res;
    }
};