#include <bits/stdc++.h>

using namespace std;

//摩尔投票法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curNum = 0, count = 0; //当前存活的数， 数的个数
        for (int &num: nums) {
            if (count == 0){
                curNum = num;
                count++;
            } else{
                if (curNum == num)
                    count++;
                else
                    count--;
            }
        }

        return curNum;
    }
};