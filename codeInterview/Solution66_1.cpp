#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //双向前缀积
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        if (n== 0 || n == 1)
            return a;

        int forwardSum[n], reverseSum[n];
        forwardSum[0] = a[0];
        reverseSum[n-1] = a[n-1];

        for (int i = 1; i < n; ++i) {
            forwardSum[i] = forwardSum[i-1] * a[i];
        }
        for (int i = n-2; i >= 0; --i) {
            reverseSum[i] = reverseSum[i+1] * a[i];
        }

        vector<int> vec(n);
        vec[0] = reverseSum[1];
        vec[n-1] = forwardSum[n-2];
        for (int i = 1; i < n-1; ++i) {
            vec[i] = forwardSum[i-1] * reverseSum[i+1];
        }

        return vec;
    }
};