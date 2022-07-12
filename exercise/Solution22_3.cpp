#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> res;
    int pairNum;

    vector<string> generateParenthesis(int n) {
        pairNum = n;
        string path;
        backTracking(0 , 0, path);

        return res;
    }

    void backTracking(int leftNum, int rightNum, string &path){
        if (leftNum > pairNum || rightNum > pairNum)
            return;
        if (rightNum > leftNum)
            return;
        if (rightNum == leftNum && rightNum == pairNum){
            res.push_back(path);
            return;
        }

        path.push_back('(');
        backTracking(leftNum + 1, rightNum, path);
        path.pop_back();

        path.push_back(')');
        backTracking(leftNum, rightNum + 1, path);
        path.pop_back();
    }
};