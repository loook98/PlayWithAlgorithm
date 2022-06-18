#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int> &cards) {
        int n = cards.size();
        int res = INT32_MAX;
        int l = 0, r = 0;
        unordered_map<int, int> map;
        while (r < n) {
            if (!map.empty() && map.count(cards[r])) {
                res = min(res, r - map[cards[r]] + 1);
            }
            r++;

            while (map.count(cards[r - 1])) {
                map.erase(cards[l]);
                l++;
            }
            map.insert({cards[r - 1], r-1});
        }

        if (res == INT32_MAX)
            return -1;
        else
            return res;
    }
};