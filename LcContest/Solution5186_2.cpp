#include <bits/stdc++.h>

using namespace std;

class RangeFreqQuery {
    unordered_map<int, vector<int>> pos; //记录每个数出现的位置
public:
    RangeFreqQuery(vector<int> &arr) {
        for (int i = 0; i < arr.size(); ++i) {
            pos[arr[i]].emplace_back(i);
        }
    }

    int query(int left, int right, int value) {
        auto it = pos.find(value);
        if (it == pos.end())
            return 0;

        const auto &p = it->second;
        //uper_bound返回第一个大于right的数的迭代器， lower返回第一个大于等于left的迭代器。两个算法的实现都是用的二分思想。
        return upper_bound(p.begin(), p.end(), right) - lower_bound(p.begin(), p.end(), left);
    }
};