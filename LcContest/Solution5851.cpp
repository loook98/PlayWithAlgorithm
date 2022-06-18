#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_set<string> set;
    string res;
    bool found = false;

    string findDifferentBinaryString(vector<string> &nums) {
        int n = nums.size();
        string temp(n, '0');
        res = temp;
        cout << res << endl;
        for (string s: nums) {
            set.emplace(s);
        }
        dfs(n, '1', 0);
        dfs(n, '0', 0);

        return res;
    }

    void dfs(int n, char ch, int depth){
        if (found)
            return;

        res[depth] = ch;
        if (depth == n-1){
            if (!set.count(res))
                found = true;
            return;
        }

        dfs(n, '1', depth+1);
        dfs(n, '0',depth+1);
    }
};