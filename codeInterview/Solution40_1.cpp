#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        if (k == 0)
            return res;
        int n = arr.size();
        priority_queue<int> pq; //c++默认是最大堆
        for (int i = 0; i < k; ++i) {
            pq.push(arr[i]);
        }

        for (int i = k; i < n; ++i) {
            if (arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }


        for (int i = 0; i < k; ++i) {
            res.emplace_back(pq.top());
            pq.pop();
        }

        return res;
    }
};






