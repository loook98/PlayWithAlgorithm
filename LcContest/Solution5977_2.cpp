#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    //滑动窗口
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int k = 0;//nums中1的个数
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1)
                k++;
        }

        vector<int> newNums(nums.end() - k,nums.end());
        newNums.insert(newNums.end(),nums.begin(), nums.end());

        int left = 0, right = 0;
        int zeroNum = 0;
        while (right < k){
            if (newNums[right] == 0)
                zeroNum++;
            right++;
        }//right = k

        int minMove = zeroNum;
        while (right < newNums.size()){
            if (newNums[right] == 0)
                zeroNum++;
            if (newNums[left] == 0)
                zeroNum--;
            left++;

            if (zeroNum < minMove)
                minMove = zeroNum;
            right++;
        }
        return minMove;
    }
};
