#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        vector<int> cur(2, 0); //cur[0]为当前存活的数， cur[1]为当前存活的数的个数

        for (int &num: nums) {
            if (cur[1] == 0){
                cur[0] = num;
                cur[1] = 1;
            } else{
                if (num == cur[0])
                    cur[1]++;
                else
                    cur[1]--;
            }
        }

        return cur[0];
    }
};