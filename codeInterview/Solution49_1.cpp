#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> factors = {2,3,5};
        priority_queue<long, vector<long>, greater<long>> heap;
        set<long> seen;
        heap.push(1L);
        seen.insert(1L);
        int ugly = 0;
        for (int i = 0; i < n; ++i) {
            long cur = heap.top();
            heap.pop();
            ugly = (int) cur;
            for (int j = 0; j < 3; ++j) {
                long num = cur * factors[j];
                if (!seen.count(num)){
                    seen.insert(num);
                    heap.push(num);
                }

            }
        }
        return ugly;
    }
};