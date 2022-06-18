#include <bits/stdc++.h>

using namespace std;

//单调栈
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<int> s;

        for (int i = n-1; i >= 0; --i) {
            while (!s.empty() && temperatures[s.top()] <= temperatures[i])
                s.pop();

            res[i] = s.empty() ? 0 : (s.top() - i);
            s.push(i);
        }
        return res;
    }
};