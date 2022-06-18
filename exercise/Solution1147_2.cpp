#include <bits/stdc++.h>

using namespace std;

//加入hash的思路
class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long *pow26;

    int longestDecomposition(string text) {
        pow26 = new long long[text.size()];
        //计算pow26
        pow26[0] = 1;
        for (int i = 1; i < text.size(); ++i) {
            pow26[i] = (pow26[i - 1] * 26) % MOD;
        }

        return solve(text, 0, text.size() - 1);
        //delete[] pow26; //Unreachable code
    }

    //返回s[left...right]的最大段数
    int solve(string s, int left, int right) {
        if (left > right) return 0;

        long long prehash = 0, posthash = 0;
        for (int i = left, j = right; i < j; ++i, --j) {
            prehash = (prehash * 26 + (s[i] - 'a')) % MOD;
            posthash = ((s[j] - 'a') * pow26[right - j] + posthash) % MOD;

            if (prehash == posthash &&
                strEqual(s, left, i, j, right)) //通过判断posthash和prehash，可以快速判断出不等的字符串，不需要进行strEqual消耗大量时间
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