#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        vector<int> left2right(n, 1);
        vector<int> right2left(n, 1);

        //从左到右遍历,只考虑「当前得分高于左边时要获得更多糖果」
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1])
                left2right[i] = left2right[i - 1] + 1;
        }
        //从右到左遍历,只考虑「当前得分高于右边时要获得更多糖果」
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1])
                right2left[i] = right2left[i + 1] + 1;
        }

        int res = 0;
        //每个位置的最终结果就是「两次遍历时的最大值」
        for (int i = 0; i < n; ++i) {
            res += max(left2right[i], right2left[i]);
        }

        return res;
    }
};