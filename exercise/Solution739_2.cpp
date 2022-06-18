#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = temperatures.size();
        vector<int> higherIndex(n);
        stack<int> increaseStack; //从栈顶到栈底一次递增,存放的是索引

        for (int i = n - 1; i >= 0; --i) {
            while (!increaseStack.empty() && temperatures[increaseStack.top()] <= temperatures[i])
                increaseStack.pop();

            if (increaseStack.empty())
                higherIndex[i] = -1;
            else
                higherIndex[i] = increaseStack.top();

            increaseStack.push(i);
        }

        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            if (higherIndex[i] == -1)
                res[i] = 0;
            else
                res[i] = higherIndex[i] - i;
        }

        return res;
    }
};