#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    set<string> set;
    vector<bool> visited;

    vector<string> permutation(string s) {
        visited = vector<bool>(s.size());
        string path;
        for (int i = 0; i < s.size(); ++i) {
            dfs(s, i, path);
        }
        vector<string> res(set.begin(), set.end());
        return res;
    }

    void dfs(string s, int chIndex,string& path){
        if (path.size() == s.size() - 1){
            path.push_back(s[chIndex]);
            set.insert(path);
            path.pop_back();
            return;
        }

        path.push_back(s[chIndex]);
        visited[chIndex] = true;
        for (int i = 0; i < s.size(); ++i) {
            if (!visited[i])
                dfs(s, i, path);
        }
        visited[chIndex] = false;
        path.pop_back();
    }
};