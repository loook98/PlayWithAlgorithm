#include <bits/stdc++.h>

using namespace std;

//双指针（快慢指针）
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int slow = 0, fast = 1;
        while (fast < n){
            if (nums[fast] != nums[slow]){
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return slow +1;
    }
};