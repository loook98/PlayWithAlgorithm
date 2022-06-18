#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> remain(n);
        for (int i = 0; i < n; ++i) {
            remain[i] = capacity[i] - rocks[i];
        }

        sort(remain.begin(), remain.end());

        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (additionalRocks <= 0)
                break;
            if (additionalRocks >= remain[i]){
                res++;
                additionalRocks -= remain[i];
            } else{
                break;
            }
        }

        return res;
    }
};