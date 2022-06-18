#include <bits/stdc++.h>

using namespace std;

//使用快排的partition思路，也是O(n)时间复杂度
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //先把一个1换到0索引处
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1){
                swap(nums[0], nums[i]);
                break;
            }
        }

        int zero = 0; //[1..zero]为0
        int i = 1; //[zero+1...i)为1
        int two = nums.size(); //[two...nums.size()-1]为2

        while (i < two){
            if (nums[i] < 1){
                zero++;
                swap(nums[zero], nums[i]);
                i++;
            } else if (nums[i] > 1){
                two--;
                swap(nums[two], nums[i]);
            } else{ // ==1
                i++;
            }
        }
        swap(nums[0],nums[zero]);
        zero--;
        return;
    }
};