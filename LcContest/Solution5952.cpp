#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPoints(string rings) {
        int n2 = rings.size();

        vector<vector<bool>> cnt(10, vector<bool>(3, false));

        int index = 0;
        while (index < n2){
            char RGBc = rings[index++];
            int RGB;
            if (RGBc == 'R')
                RGB = 0;
            else if (RGBc == 'G')
                RGB = 1;
            else
                RGB = 2;
            int ringNum = (rings[index++] - '0');
            if (!cnt[ringNum][RGB])
                cnt[ringNum][RGB] = true;
        }

        int ret = 0;
        for (int i = 0; i < 10; ++i) {
            if (cnt[i][0] && cnt[i][1] && cnt[i][2])
                ret++;
        }


        return ret;
    }
};