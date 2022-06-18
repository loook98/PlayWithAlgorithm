#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int l = 0, r = n - 1;
        while (l <= r){
            int mid = l + (r - l)/2;

            if (0 == mid && nums[mid] != nums[mid+1]){
                return nums[mid];
            } else if (n - 1 == mid && nums[mid] != nums[mid-1]){
                return nums[mid];
            } else{
                if ( nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
                    return nums[mid];
            }

            int same = 0;
            if (mid - 1 >= 0 && nums[mid-1] == nums[mid])
                same = mid - 1;
            if (mid + 1 < n && nums[mid + 1] == nums[mid])
                same = mid + 1;

            //哪边是奇数就继续在哪边寻找
            if ( min(same, mid) % 2 != 0){
                r = min(same, mid) - 1;
            } else{
                l = max(same, mid) + 1;
            }
        }
        //没有出现1次的数
        return -1;
    }
};