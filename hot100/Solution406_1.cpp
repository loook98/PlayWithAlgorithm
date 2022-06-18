#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int> c1, vector<int> c2) {
        if (c1[0] != c2[0])
            return c1[0] < c2[0];
        else
            return c1[1] < c2[1];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        int n = people.size();
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res(n);
        vector<int> freePos(n + 1, 0); //freePos[i]表示 res[0...i-1]中还有几个空位置
        for (int i = 1; i <= n; ++i) {
            freePos[i] = i;
        }

        int sameCount = 0; //记录当前元素之前和该元素相等的元素个数
        for (int i = 0; i < n; ++i) {
            if (i > 0 && people[i][0] == people[i - 1][0])
                sameCount++;
            else
                sameCount = 0;

            int pos = people[i][1] - sameCount;
            for (int j = pos; j < n; ++j) { //从pos处向后找合适的位置
                //合适的位置: 【当前位置没有被使用 && 当前位置以前空位置 == pos】
                if (freePos[j + 1] - freePos[j + 1 - 1] && freePos[j + 1] - 1 == pos) {
                    res[j] = people[i];
                    //更新freePos
                    for (int k = j + 1; k <= n; ++k)
                        freePos[k]--;
                    break;
                }
            }
        }
        return res;
    }
};