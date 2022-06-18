#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<pair<int, int>> degressiveStack; //栈中存放当前还没有决定结果（几天后有更高温度）的元素
        int n = temperatures.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            if (degressiveStack.empty()
                || temperatures[i] <= degressiveStack.top().second) {
                degressiveStack.emplace(i, temperatures[i]);
            } else{
                while ( !degressiveStack.empty() && temperatures[i] > degressiveStack.top().second){
                    pair<int, int> element = degressiveStack.top();
                    degressiveStack.pop();
                    res[element.first] = i - element.first;
                }
                degressiveStack.emplace(i, temperatures[i]);
            }
        }
        return res;
    }
};