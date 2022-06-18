#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ret = 0;
        while (target > 1){
            if (maxDoubles <= 0){
                ret += target-1;
                break;
            }
            if (target % 2 == 0){
                target = target / 2;
                maxDoubles--;
                ret++;
            } else{
                target--;
                ret++;
            }
        }
        return ret;
    }
};