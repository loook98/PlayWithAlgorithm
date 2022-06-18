#include <bits/stdc++.h>

using namespace std;

//原地哈希： 一个元素num哈希后对应的位置为num-1
//先原地哈希：将每个元素放到它哈希后对应的位置（如果在数组范围的话）【注意：不能简单的遍历一遍，因为这样可能会覆盖元素】
//再遍历一遍数组：找到第一个索引i处存的元素≠(i+1),则(i+1)就是第一个没有出现的数。若找不到这样的数，则第一个没出现的数为n+1(n为数组大小).
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        //原地计算哈希
        for (int i = 0; i < n; ++i) {
            while (nums[i] != i + 1){
                if (nums[i] <= 0 || nums[i] > n || nums[i] == nums[nums[i] - 1])
                    break;
                int idx = nums[i] - 1;
                nums[i] = nums[idx];
                nums[idx] = idx + 1;
            }
        }
        //寻找结果
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};

int main(){
    vector<int> nums = {3,4,-1,1};
    Solution().firstMissingPositive(nums);
}