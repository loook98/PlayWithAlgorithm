#include <bits/stdc++.h>

using namespace std;

//一次考虑每个柱子的情况：
// 左边第一个小于它的元素坐标x,右边第一个小于它的元素坐标y, (y-x-1)*height就是这个柱子能构成的最大面积
// 考虑使用单调栈来构建下一个(或上一个)小于坐标数组
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> rNextLess(n);
        vector<int> lNextLess(n);
        stack<int> rStack;
        stack<int> lStack;

        for (int i = n-1; i >= 0; --i) {
            while (!rStack.empty() && heights[rStack.top()] >= heights[i])
                rStack.pop();
            if (rStack.empty())
                rNextLess[i] = n;
            else
                rNextLess[i] = rStack.top();
            rStack.push(i);
        }
        for (int i = 0; i < n; ++i) {
            while (!lStack.empty() && heights[lStack.top()] >= heights[i])
                lStack.pop();
            if (lStack.empty())
                lNextLess[i] = -1;
            else
                lNextLess[i] = lStack.top();
            lStack.push(i);
        }

        //计算结果
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int size = (rNextLess[i] - lNextLess[i] - 1) * heights[i];
            res = max(res, size);
        }
        return res;
    }
};