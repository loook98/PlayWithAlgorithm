#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0; //i用来遍历数组
        int k = 0; //★nums[0,k)内为非零数

        for (i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0){
                swap(nums[k], nums[i]);
                k++;
            }
        }


        //多余，不需要
//        //遍历完数组，[0,k)为非零数，将[k,size-1]改为0
//        for ( ; k < nums.size(); ++k) {
//            nums[k] = 0;
//        }
    }
};