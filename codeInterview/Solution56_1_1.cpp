#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //看了题解
    //如果数组中只有1个元素出现了1次，其他元素都出现了2次。 那么数组中所有元素异或之后就是只出现一次的元素： a⊕a⊕b⊕b⊕...⊕x = 0⊕0⊕...⊕x = x 。（异或满足交换律）
    //这个问题的难点在于有2个元素出现了1次。要将数组划分成两个只有1个元素出现1次，其他元素出现2次的子数组。
    vector<int> singleNumbers(vector<int> &nums) {
        int x = 0, y = 0, n = 0, m = 1;
        //循环异或，最后求到的值n是两个只出现1次的数(x和y)的异或
        for (int num: nums) {
            n ^= num;
        }
        //n中为1的位是x和y不相同的位
        while ((n & m) == 0)
            m <<= 1;
        //将数组分组异或计算值
        for (int num: nums) {
            if (num & m)
                x ^= num;
            else
                y ^= num;
        }
        return vector<int>{x, y};
    }
};