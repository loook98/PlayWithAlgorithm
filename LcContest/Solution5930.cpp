#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxDist = INT32_MIN;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (colors[i] != colors[j] && j - i > maxDist)
                    maxDist = j - i;
            }
        }

        assert(maxDist != INT32_MIN);
        return maxDist;
    }
};