#include <bits/stdc++.h>

using namespace std;

//5236. 美化数组的最少删除数
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;
        int res = 0;
        int even = 0, odd = 1;

        while (odd < n){
            if (nums[odd] == nums[even]){
                res++;
                odd++;
            } else{
                even = odd + 1;
                odd += 2;
            }
        }
        if (odd == n || even == n-1)
            res++;

        return res;
    }
};