#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> res;
    int N;

    vector<string> generateParenthesis(int n) {
        N = n;
        string path;
        dfs(0, path, 0, 0);
        return res;
    }

    void dfs(int level, string &path, int leftNumber, int rightNumber) {
        if (rightNumber > leftNumber || leftNumber > N)
            return;
        if (level == 2 * N) {
            res.push_back(path);
            return;
        }

        path.push_back('(');
        dfs(level + 1, path, leftNumber + 1, rightNumber);
        path.pop_back();

        path.push_back(')');
        dfs(level + 1, path, leftNumber, rightNumber + 1);
        path.pop_back();
    }
};