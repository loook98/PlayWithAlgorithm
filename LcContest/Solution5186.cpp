#include <bits/stdc++.h>

using namespace std;

//会超时
class RangeFreqQuery {
public:
    vector<int> nums;
    vector<unordered_map<int, int>> preFreq;
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        nums = vector<int>(arr.begin(), arr.end());
        preFreq = vector<unordered_map<int, int>>(n);

        //
        preFreq[0][nums[0]]++;
        for (int i = 1; i < n; ++i) {
            preFreq[i] = preFreq[i-1];
            preFreq[i][nums[i]]++;
        }
    }

    int query(int left, int right, int value) {
        int freq = preFreq[right][value] - preFreq[left][value];
        if (nums[left] == value)
            freq++;
        return freq;
    }
};