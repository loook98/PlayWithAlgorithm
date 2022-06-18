#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        unordered_set<int> used;
        vector<long long> noRepeat;
        for (int num : nums) {
            if(!used.count(num))
                noRepeat.push_back(num);
            used.insert(num);
        }
        sort(noRepeat.begin(), noRepeat.end());

        long long res = 0;
        int left = 0, right = 1;

        if (k >= noRepeat[0] - 1){
            k -= noRepeat[0] - 1;
            res += (long long)(1 + noRepeat[0] - 1) * (long long)(noRepeat[0] - 1) / 2;
        } else{
            res += (1 + k) * (long long)k / 2;
            k = 0;
        }
        while (noRepeat.size() != 1 && right < noRepeat.size()){
            if (k == 0)
                return res;
            long long windowNum = noRepeat[right] - noRepeat[left] - 1;
            if (k >= windowNum){
                k -= windowNum;
                res += (noRepeat[left]+1 + noRepeat[right]-1) * (long long)windowNum / 2;
            } else{
                res += (noRepeat[left]+1 + noRepeat[left]+k) *(long long)k / 2;
                k = 0;
            }
            left++;
            right++;
        }
        cout << res;
        if (k != 0)
            res += (noRepeat[noRepeat.size()-1]+1 + noRepeat[noRepeat.size()-1]+k)*(long long)k/2;
        return res;
    }
};