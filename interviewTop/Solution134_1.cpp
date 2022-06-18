#include <bits/stdc++.h>

using namespace std;

//暴力，最后一个用例超时
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        vector<int> remain(n); //remain[i]表示从i加油站开始的这段路走完后剩余的油量
        for (int i = 0; i < n; ++i)
            remain[i] = gas[i] - cost[i];

        for (int i = 0; i < n; ++i) {
            vector<bool> visited(n, false);
            if (remain[i] >= 0) {
                int curRemain = 0, j;
                for (j = i; !visited[j]; j = (j + 1) % n) {
                    visited[j] = true;
                    curRemain += remain[j];
                    if (curRemain < 0)
                        break;
                }
                if (j == i)
                    return i;
            }
        }
        return -1;
    }
};