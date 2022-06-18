#include <bits/stdc++.h>

using namespace std;

//838. 推多米诺
class Solution {
public:
    //双指针
    // <--L...R--> ，中间不变
    // R-->...<--L ，看中间是偶数个还是奇数个决定是否有个立着
    // <--L...<--L ，中间全是L
    // R-->...R--> , 中间全是R
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        //先将最左边和最右边进行处理
        int preI, preJ;
        for (preI = 0; preI < n; ++preI) {
            if (dominoes[preI] != '.')
                break;
        }
        if (preI == n)
            return dominoes;
        else if (dominoes[preI] == 'L') {
            for (int i = 0; i < preI; ++i) {
                dominoes[i] = 'L';
            }
        }

        for (preJ = n - 1; preJ >= 0; --preJ) {
            if (dominoes[preJ] != '.')
                break;
        }
        if (dominoes[preJ] == 'R') {
            for (int i = n - 1; i > preJ; --i) {
                dominoes[i] = 'R';
            }
        }

        if (preI == preJ)
            return dominoes;

        //双指针移动，处理两个指针中间的部分
        int left = preI, right = preI + 1;
        while (right < n){
            if (dominoes[right] != '.'){
                if (dominoes[left] == dominoes[right]){
                    for (int i = left + 1; i < right; ++i) {
                        dominoes[i] = dominoes[left];
                    }
                } else if (dominoes[left] == 'R'){
                    int i, j;
                    for (i = left + 1, j = right - 1; i < j; ++i, --j) {
                        dominoes[i] = 'R';
                        dominoes[j] = 'L';
                    }
                }

                left = right;
            }
            right++;
        }

        return dominoes;
    }
};