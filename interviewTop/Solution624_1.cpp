#include <bits/stdc++.h>

using namespace std;

//计数,按位置填充
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(5001, 0); //计数，统计各个数出现次数。
        for (int num : nums) {
            cnt[num]++;
        }

        //奇数 [小大小大小]
        //偶数 [小大小大]
        int smallEndIndex = 0, bigEndIndex = 0;
        if ((n & 1) == 1){ //奇数
            smallEndIndex = n -1;
            bigEndIndex = n - 2;
        } else{
            smallEndIndex = n - 2;
            bigEndIndex = n - 1;
        }

        int cntI = 5000;
        //填充大的数
        for (int i = 1; i <= bigEndIndex; i+=2) {
            while (cnt[cntI] == 0)
                cntI--;
            nums[i] = cntI;
            cnt[cntI]--;
        }
        //填充大的数
        for (int i = 0; i <= smallEndIndex; i+=2) {
            while (cnt[cntI] == 0)
                cntI--;
            nums[i] = cntI;
            cnt[cntI]--;
        }
    }
};