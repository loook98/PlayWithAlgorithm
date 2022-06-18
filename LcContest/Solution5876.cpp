#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOfBeauties(vector<int> &nums) {
        int n = nums.size();
        int prefixMax[n], postfixMin[n];

        prefixMax[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > prefixMax[i - 1])
                prefixMax[i] = nums[i];
            else
                prefixMax[i] = prefixMax[i - 1];
        }

        postfixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < postfixMin[i + 1])
                postfixMin[i] = nums[i];
            else
                postfixMin[i] = postfixMin[i + 1];
        }

        int res = 0;
        for (int i = 1; i <= n - 2; ++i) {
            if (nums[i] > prefixMax[i - 1] && nums[i] < postfixMin[i + 1]) { //情况1
                res += 2;
            } else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1]){
                res += 1;
            }
        }
        return res;
    }
};