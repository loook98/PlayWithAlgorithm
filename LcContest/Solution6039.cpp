#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.push(num);
        }


        for (int i = 0; i < k; ++i) {
            int min = pq.top();
            pq.pop();
            pq.push(min+1);
        }

        long long res = 1;
        while (!pq.empty()){
            int num = pq.top();
            pq.pop();
            res = (res% 1000000007 * num% 1000000007) % 1000000007;
        }
        return res;
    }
};