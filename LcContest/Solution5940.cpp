#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIndex= 0, maxIndex = 0;
        int minNum = INT32_MAX, maxNum = INT32_MIN;

        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] < minNum){
                minNum = nums[i];
                minIndex = i;
            }

            if (nums[i] > maxNum){
                maxNum = nums[i];
                maxIndex = i;
            }
        }

        int choose1 = max(minIndex, maxIndex) + 1;//从前边删
        int choose2 = n - min(minIndex, maxIndex); //从后边删
        int choose3 = (min(minIndex, maxIndex) + 1) + (n - max(minIndex, maxIndex));

        return min(choose1, min(choose2, choose3));
    }
};