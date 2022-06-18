#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        vector<int> diffBetweenFront(n);
        diffBetweenFront[0] = 0;
        for (int i = 1; i < n; ++i) {
            diffBetweenFront[i] = prices[i] - prices[i-1];
        }

        long long ret = 0;
        int len = 0;//保存当前全为1的连续子串长度
        for (int i = 1; i < n; ++i) {
            if (diffBetweenFront[i] == -1){
                len++;
            } else{
                if (len != 0){
                    ret += countSeqSubset(len+1);
                    len = 0;
                }
            }
        }
        if (len != 0)
            ret += countSeqSubset(len+1);

        //还要加上所有单个元素的子集个数
        ret += n;
        return ret;
    }

    //计算长度为n的集合中长度为2~n的所有子集个数
    long long countSeqSubset(long long n){
        return (n-1)*(n)/2;
    }

};