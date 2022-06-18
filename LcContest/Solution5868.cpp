#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>> &rectangles) {

        int n = rectangles.size();
        if (n == 1)
            return 0;
        vector<double> ratio(n);

        for (int i = 0; i < n; ++i) {
            ratio[i] = static_cast<double>(rectangles[i][0]) / rectangles[i][1];
        }
        sort(ratio.begin(), ratio.end());

        int sameNum = 1; //当前相同的元素个数
        long long res = 0;
        for (int i = 1; i < n; ++i) {
            if (ratio[i] == ratio[i - 1]) {
                sameNum++;
                if (i == n-1 && sameNum >= 2)
                    res += Cn2(sameNum);
            } else {
                if (sameNum >= 2)
                    res += Cn2(sameNum);
                sameNum = 1;
            }
        }
        return res;
    }

    long long Cn2(int n) {//n需要>=2
        long long ret = 0;
        for (int i = 1; i <= n - 1; ++i) {
            ret += i;
        }
        return ret;
    }
};