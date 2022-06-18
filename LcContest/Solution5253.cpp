#include <bits/stdc++.h>

using namespace std;

//5253. 找到指定长度的回文数
class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int n = queries.size();
        bool isEven = (intLength % 2 == 0); //计算intLength是否为偶数
        int halfLen = intLength/2 + (isEven ? 0 : 1);
        vector<long long> res(n);
        for (int i = 0; i < n; ++i) {
            string resStr;
            long long halfVal = calculateHalfVal(halfLen, queries[i]);
            resStr += to_string(halfVal);
            if (!isEven)
                halfVal /= 10;
            while (halfVal > 0){
                resStr.push_back('0' + (halfVal % 10));
                halfVal /= 10;
            }

            res[i] = stoll(resStr);
        }
        return res;
    }

    //计算长度为halLen的第order小元素
    long long calculateHalfVal(int halfLen, int order){
        long long start = (long long)pow(10, halfLen -1);
        if (order > start * 9)
            return -1;
        return start + (order - 1);
    }
};