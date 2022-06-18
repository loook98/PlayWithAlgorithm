#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int one = INT32_MAX, two = INT32_MAX;
        for (int three : nums) {
            if (three > two)
                return true;
            else if (three < one)
                one = three;
            else if (three < two)
                two = three;
        }
        return false;
    }
};