#include <bits/stdc++.h>

using namespace std;

//递归,超时
class Solution {
public:
    int minDistance(string word1, string word2) {
        return dp(word1, word2, word1.size()-1, word2.size()-1);
    }

    int dp(const string& w1, const string& w2, int i, int j){//i为word1的坐标，j为word2的坐标
        if (i == -1)
            return j + 1;
        if (j == -1)
            return i + 1;

        if (w1[i] == w2[j]){
            return dp(w1, w2, i-1, j-1);
        } else{
            //min(插入，删除，替换)
            return min(
                    dp(w1, w2, i, j-1) + 1,
                    min(dp(w1, w2, i-1, j) +1,
                        dp(w1, w2, i-1, j-1)+ 1)
                    );
        }
    }
};