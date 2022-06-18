#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> res;
    vector<bool> visited;

    vector<string> permutation(string s) {
        visited = vector<bool>(s.size(), false);
        if (s == "")
            return res;

        findpermutation(s, 0, "");
        return res;
    }

    void findpermutation(string s, int index, string p) {
        if (index == s.size()) {
            res.emplace_back(p);
            return;
        }

        set<char> repeat;
        for (int i = 0; i < s.size(); ++i) {
            if (!visited[i] && !repeat.count(s[i])) {
                repeat.insert(s[i]);

                visited[i] = true;
                p.push_back(s[i]);
                findpermutation(s, index + 1, p);
                p.pop_back();
                visited[i] = false;
            }
        }
    }

};
