#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> mapL;
        unordered_map<int,int> mapW;

        for (auto match : matches) {
            mapW[match[0]]++;
            mapL[match[1]]++;
        }

        vector<vector<int>> res(2);
        for(auto win : mapW){
            if (!mapL.count(win.first))
                res[0].push_back(win.first);
        }
        for (auto loser : mapL) {
            if (loser.second == 1)
                res[1].push_back(loser.first);
        }

        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        return res;
    }
};