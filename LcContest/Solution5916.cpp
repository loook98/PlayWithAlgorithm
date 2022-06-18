#include <bits/stdc++.h>

using namespace std;

//No.5916 转化数字的最小运算数
class Solution {
public:
    int minimumOperations(vector<int> &nums, int start, int goal) {
        int n = nums.size();
        auto op1 = [](int x, int y) -> int { return x + y; };
        auto op2 = [](int x, int y) -> int { return x - y; };
        auto op3 = [](int x, int y) -> int { return x ^ y; };
        vector<function<int(int, int)>> ops = {op1, op2, op3};

        vector<bool> visited(1001, false);
        queue<pair<int, int>> queue; // pair<val, steps>
        queue.emplace(make_pair(start, 0));
        visited[start] = true;

        while (!queue.empty()) {
            auto pair = queue.front();
            queue.pop();
            for (int i = 0; i < n; ++i) {
                for (auto &op : ops) {
                    int res = op(pair.first, nums[i]);
                    if (res == goal)
                        return pair.second + 1;
                    if (res >= 0 && res <= 1000 && !visited[res]){
                        visited[res] = true;
                        queue.emplace(res, pair.second + 1);
                    }
                }
            }
        }
        return -1;
    }
};