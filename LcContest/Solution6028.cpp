#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        if (n == 1)
            return 0;
        int res = 0;
        string afterLR;//从左向右遍历一遍后剩余车辆情况
        int r = 0, s = 0;
        for (int i = 0; i < n; ++i) {
            if (directions[i] == 'L'){
                if (r == 0 && s == 0)
                    afterLR.push_back('L');
                else if (r != 0){
                    res += r + 1;
                    r = 0;
                    s = 1;
                    afterLR.push_back('S');
                } else { //s!=0
                    res++;
                    afterLR.push_back('S');
                }
            } else if (directions[i] == 'R'){
                r++;
            } else{//S
                res += r;
                r = 0;
                s = 1;
                afterLR.push_back('S');
            }
        }
        cout << res << endl;
        //从右向左遍历
        int l = 0;
        s = 0;
        for (int i = afterLR.size() - 1; i >= 0; --i) {
            if (afterLR[i] == 'R'){
                if (l == 0 && s == 0)
                    continue;
                else if (l != 0){
                    res += l;
                    l = 0;
                    s = 1;
                } else{
                    res++;
                }
            } else if (afterLR[i] == 'L'){
                l++;
            } else{
                res += l;
                l = 0;
                s = 1;
            }
        }

        return res;
    }
};