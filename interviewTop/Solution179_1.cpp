#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool comp(const int a, const int b){
        return _comp(to_string(a), to_string(b));
    }


    static bool _comp(const string& a, const string& b) {
        if (a[0] == '0')
            return false;
        if (b[0] == '0')
            return true;

        int i = 0;
        while (i < a.size() && i < b.size()) {
            if (a[i] != b[i])
                return a[i] > b[i];
            else
                i++;
        }
        //两字符串相同
        if (a.size() == b.size())
            return true;
        else if(a.size() < b.size()) //两字符串剩余长度不同
            return _comp(a, b.substr(i, (b.size() - i)));
        else
            return _comp(a.substr(i, (a.size() - i)), b);
    }

    string largestNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end(), comp);
        string ans;

        for (const int num : nums) {
            ans += to_string(num);
        }
        return ans[0] == '0' ? "0" : ans;
    }
};