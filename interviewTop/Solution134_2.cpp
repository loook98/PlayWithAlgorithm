#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0, min = INT32_MAX;
        int start = 0;

        for (int i = 0; i < n; ++i) {
            sum += gas[i] - cost[i];
            if (sum < min){
                min = sum;
                start = i + 1;
            }
        }

        if (sum < 0)
            return -1;
        return start == n ? 0 : start;
    }
};