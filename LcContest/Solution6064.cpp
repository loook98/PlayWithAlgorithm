#include <bits/stdc++.h>

using namespace std;

//6064. 不含特殊楼层的最大连续楼层数
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int res = special[0] - bottom;
        for (int i = 1; i < special.size(); ++i) {
            res = max(res, special[i] - special[i-1] - 1);
        }
        res = max(res, top - special[special.size()-1]);

        return res;
    }
};