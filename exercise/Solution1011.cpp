#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        //因为不能拆封包裹，所以最少的运输量应为包裹中最重的物品
        int left = getMax(weights);
        //最大运输量right.
        //二分搜索区间[left,right)
        int right = getSum(weights) + 1;

        while (left < right){
            int mid = left + (right - left)/2;
            if (canFinish(weights, mid, days)){
                right = mid;
            } else{
                left = mid + 1;
            }
        }
        return left;
    }

    bool canFinish(vector<int>& weights, int load, int days){
        int count = 1;
        int remain = load;
        for(int w : weights){
            if (remain < w){
                remain = load;
                count++;
            }
            remain -= w;
        }
        return count <= days;
    }

    int getMax(vector<int>& weights){
        int _max = 0;
        for (int weight : weights) {
            _max = max(_max, weight);
        }
        return _max;
    }

    int getSum(vector<int>& weights){
        int sum = 0;
        for (int w : weights) {
            sum += w;
        }
        return sum;
    }
};