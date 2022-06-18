#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int pancake1 = 0;//记录剩余未排序的元素中最大的数的位置
        int pancake2 = arr.size();//记录剩余未排序的元素个数

        vector<int> ret;
        while(pancake2 > 1){
            //找到pancake1的位置
            pancake1 = 0;
            bool isSorted = true; //用于判断当前剩余元素是否已经有序
            for (int i = 0; i < pancake2; ++i) {
                if (i+1 != arr[i])
                    isSorted = false;
                if (arr[i] > arr[pancake1])
                    pancake1 = i;
            }
            if (isSorted)
                break;
            //把当前最大的元素挪到数组最开头
            if (pancake1 != 0 && pancake1 != pancake2 - 1){
                reverse(arr.begin(), arr.begin() + pancake1 + 1);
                ret.push_back(pancake1+1);
            }

            //然后再把数组最开头元素挪到它排序后应在的位置
            if (pancake1 != pancake2 - 1){
                reverse(arr.begin(), arr.begin() + pancake2);
                ret.push_back(pancake2);
            }

            //更新pancake2
            pancake2--;
        }
        return ret;
    }
};