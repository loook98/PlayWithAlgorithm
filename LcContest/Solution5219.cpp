#include <bits/stdc++.h>

using namespace std;

//error
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int candy : candies) {
            if (pq.size() == k){
                pq.pop();
            }
            pq.push(candy);
        }

        int res = 0;
        do {
            res = pq.top();
            //用最小堆的话这样没法找到最大的拆分了
        } while (pq.top() >= res);

    }
};