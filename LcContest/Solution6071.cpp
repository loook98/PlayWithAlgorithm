#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumRounds(vector<int> &tasks) {
        unordered_map<int, int> map;
        for (int task : tasks) {
            map[task]++;
        }

        int res = 0;

        for (auto pair : map) {
            int num = pair.second;
            if (num == 1)
                return -1;
            int remain = num % 3;

            if (remain == 0){
                res += num / 3;
            } else if (remain == 1){
                res += (num / 3) - 1;
                res += 2;
            } else{
                res += num / 3;
                res += 1;
            }
        }
        return res;
    }
};