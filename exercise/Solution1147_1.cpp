#include <bits/stdc++.h>

using namespace std;

//不使用hash的算法
class Solution {
public:

    int longestDecomposition(string text) {
        return solve(text, 0, text.size() - 1);
    }

    //返回s[left...right]的最大段数
    int solve(string s, int left, int right) {
        if (left > right) return 0;

        for (int i = left, j = right; i < j; ++i, --j) {
            if (strEqual(s, left, i, j, right))
                return solve(s, i + 1, j - 1) + 2;
        }
        return 1;
    }

    //判断s[l1..r1]和s[l2,r2]两个字符串是否相等
    bool strEqual(string s, int l1, int r1, int l2, int r2) {
        for (int i = l1, j = l2; i <= r1 && j <= r2; ++i, ++j) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
};