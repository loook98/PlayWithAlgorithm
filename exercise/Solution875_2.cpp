#include <bits/stdc++.h>

using namespace std;

//使用二分优化暴力搜索的过程
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = getMax(piles) + 1;

        //二分搜索区间为[left, right)
        while (left < right){
            int mid = left + (right - left)/2;
            if (canFinish(piles, mid, h)){
                right = mid;
            } else{ //不可完成。此时区间一定是更大的那部分，因为更小的部分也一定不能完成
                left = mid + 1;
            }
        }
        return left;
    }

    bool canFinish(vector<int>& piles, int speed, int h){
        int time = 0;
        for (int n : piles) {
            time += timeOf(n, speed);
        }
        return time <= h;
    }

    int timeOf(int n, int speed){
        return (n / speed) + ((n % speed) > 0 ? 1 : 0);
    }

    int getMax(vector<int>& piles){
        int _max = 0;
        for (int n : piles) {
            _max = max(_max, n);
        }
        return _max;
    }
};