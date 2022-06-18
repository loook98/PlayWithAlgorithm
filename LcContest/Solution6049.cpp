#include <bits/stdc++.h>

using namespace std;

//错误
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int canDivide = 0;

            for (int j = i; j < n; ) {
                if (nums[j] % p == 0)
                    canDivide++;
                if (canDivide > k)
                    break;

                while (i > 0 && (nums[i-1] == nums[i]) && (nums[j] == nums[i])){
                    j++;
                }
                if (j >= n)
                    break;
                res++;

                //
                ++j;
            }
        }
        return res;
    }
};