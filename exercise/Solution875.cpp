#include <bits/stdc++.h>

using namespace std;

//暴力解法
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = getMax(piles);
        //speed为每小时可吃的香蕉数
        //递增speed，找到可以在规定时间内吃完所有香蕉的最小速度
        for (int speed = 1; speed < maxPile; ++speed) {
            if (canFinish(piles, speed, h))
                return speed;
        }
        return maxPile;
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