#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> res;
    int N;

    vector<string> generateParenthesis(int n) {
        N = n;
        dfs(0, "", 0, 0);
        return res;
    }

    void dfs(int level, string path, int leftNumber, int rightNumber) {
        if (rightNumber > leftNumber || leftNumber > N)
            return;
        if (level == 2 * N) {
            res.push_back(path);
            return;
        }

        dfs(level + 1, path + "(", leftNumber + 1, rightNumber);
        dfs(level + 1, path + ")", leftNumber, rightNumber + 1);
    }
};