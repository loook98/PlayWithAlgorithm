#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        slow = nums[slow];
        fast = nums[nums[fast]];

        while (slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        while (nums[slow] != nums[fast]){
            slow = nums[slow];
            fast = nums[fast];
        }

        return nums[slow];
    }
};