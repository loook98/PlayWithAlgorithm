#include <bits/stdc++.h>

using namespace std;

//将数组先分成两个子数组。每个数组中只包含一个只出现一次的数。再分别得出那个只出现一次的数。
class Solution {
public:
    vector<int> singleNumbers(vector<int> &nums) {
        //先异或数组中的所有元素，结果就是那两个只出现一次的数的异或结果。
        //又因为这两个数不相等，所以它两的异或结果必定有1位是1.
        //判断一个数的该位是否为1即可将原数组分为两个新数组。
        int xorOf2res = 0;
        for (int num : nums) {
            xorOf2res ^= num;
        }

        int bit = 1;
        while ((xorOf2res & bit) == 0)
            bit <<= 1;

        vector<int> sub1, sub2;
        for (int num : nums) {
            if ((num & bit) == 0)
                sub1.push_back(num);
            else
                sub2.push_back(num);
        }

        vector<int> res;
        res.push_back(oneSingleNumbers(sub1));
        res.push_back(oneSingleNumbers(sub2));

        return res;
    }

    //辅助函数。传入的nums中只有一个数只出现一次，其他数均出现两次。
    int oneSingleNumbers(vector<int> &nums){
        int ret = 0;
        for (int num : nums) {
            ret ^= num;
        }
        return ret;
    }
};