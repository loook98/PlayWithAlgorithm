#include <bits/stdc++.h>

using namespace std;

//贪心
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int steps = 0;//表示跳的次数，起跳的一次，steps++。
        int end = 0; //在[i...end]这个区间内选择一点起跳
        int maxPos = 0;//记录在[i...end]这个区间内的起跳可以到达的最远位置。用于更新下一个区间的end值。

        //注：初始条件i=0 == end条件一定满足。即第一个点一定要起跳，steps要++。
        for (int i = 0; i < n - 1; ++i) {
            maxPos = max(maxPos, i + nums[i]);
            if (i == end){//当前这个区间内的起跳点已确定，steps++
                steps++;
                end = maxPos; //更新区间的end值。开始从下一个区间内选起跳点
            }
        }
        return steps;
    }
};