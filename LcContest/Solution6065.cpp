#include <bits/stdc++.h>

using namespace std;

//6065. 按位与结果大于零的最长组合
//会超时
class Solution {
public:
    int res = 0;
    vector<unordered_map<int, int>> levelMax; //当前层对于当前与的结果值对应的最大长度
    int largestCombination(vector<int> &candidates) {
        levelMax = vector<unordered_map<int, int>>(candidates.size());
        dfs(candidates, 0, INT32_MAX, 0);
        return res;
    }

    void dfs(vector<int> &candidates, int level, int andVal, int len) {
        if (level == candidates.size()) {
            return;
        }

        int newAndVal = andVal & candidates[level];
        if (newAndVal != 0 &&
                (levelMax[level].count(newAndVal) ? len + 1 > levelMax[level][newAndVal] : true)) {
            res = max(res, len + 1);
            levelMax[level][newAndVal] = len + 1;
            dfs(candidates, level + 1, newAndVal, len + 1);
        }
        dfs(candidates, level + 1, andVal, len);
    }
};