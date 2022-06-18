#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        unordered_set<int> digSet;
        for (auto d :dig) {
            digSet.insert((d[0] << 10) | d[1]);
        }

        int res = 0;
        for (auto artifact : artifacts) {
            int r1 = artifact[0];
            int c1 = artifact[1];
            int r2 = artifact[2];
            int c2 = artifact[3];
            vector<int> points;
            for (int i = r1; i <= r2; ++i) {
                for (int j = c1; j <= c2; ++j) {
                    points.push_back((i << 10) | j);
                }
            }

            bool dontCover = false;
            for (int point : points) {
                if (!digSet.count(point)){
                    dontCover = true;
                    break;
                }
            }
            if (!dontCover)
                res++;
        }
        return res;
    }
};