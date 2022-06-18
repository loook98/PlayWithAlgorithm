#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int, int> evenIndex;
        map<int, int> oddIndex;

        if(nums.size() == 1)
            return 0;
        //统计各个数字出现的频率
        int totalEven = 0;
        for (size_t i = 0; i < nums.size(); i+=2)
        {
            evenIndex[nums[i]]++;
            totalEven++;
        }

        int totalOdd = 0;
        for (size_t i = 1; i < nums.size(); i+=2)
        {
            oddIndex[nums[i]]++;
            totalOdd++;
        }

        //map转换成vector，之后排序
        vector<pair<int ,int>> vtEven(evenIndex.begin(), evenIndex.end());

        vector<pair<int , int >> vtOdd(oddIndex.begin(), oddIndex.end());

        sort(vtEven.begin(), vtEven.end(), [](const pair<int, int> &x, const pair<int, int> &y) -> bool {
            return x.second > y.second;});

        sort(vtOdd.begin(), vtOdd.end(), [](const pair<int, int> &x, const pair<int, int> &y) -> bool {
            return x.second > y.second;});

        //计算返回结果
        int ret = 0;
        int n = nums.size();
        if (vtEven[0].first != vtOdd[0].first)
        {
            ret = (totalEven - vtEven[0].second) + (totalOdd - vtOdd[0].second);
        } else{ //偶数和奇数位置出现次数最多的数相等的情况
            //选择保留偶数位置
            int res1 = (totalEven - vtEven[0].second) + (totalOdd - (vtOdd.size() > 1 ? vtOdd[1].second : 0));
            //选择保留奇数位置
            int res2 = (totalOdd - vtOdd[0].second) + (totalEven - (vtEven.size() > 1 ? vtEven[1].second : 0));
            ret = min(res1, res2);
        }
        return ret;
    }
};
