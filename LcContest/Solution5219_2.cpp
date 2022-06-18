#include <bits/stdc++.h>

using namespace std;

//寻找右边界的二分搜索
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        if (k > getSum(candies))
            return 0;

        int left = 1; //每个小孩最少拿的糖果数是1
        int right = getMax(candies) + 1; //最多拿的糖果数为candies中最大的堆，因为右边开区间，所以+1

        while (left < right){
            int mid = left + (right - left)/2;
            if (canFinish(candies, mid, k)){
                left = mid + 1; //向右缩小区间
            } else{//当前可以拿的个数不符合的话只能减小拿的数
                right = mid; //向左缩小区间
            }
        }
        return left - 1;
    }

    bool canFinish(const vector<int>& candies, int canTake, long long k){
        long long kids = 0; //按每个小孩拿canTake个糖，candies可分给多少个小孩
        for (int candy : candies) {
            kids += candy / canTake;
            if (kids >= k)
                return true;
        }
        return false;
    }

    int getMax(const vector<int>& candies){
        int maxV = 0;
        for (int candy : candies) {
            maxV = max(maxV, candy);
        }
        return maxV;
    }

    long long getSum(const vector<int>& candies){
        long long sum = 0;
        for (int candy : candies) {
            sum += candy;
        }
        return sum;
    }
};