#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nextBeautifulNumber(int n) {
        for (int i = n + 1; i <= INT32_MAX; ++i) {
            string str = to_string(i);
            if (isEquilibrium(str)){
                int res = stoi(str);
                return res;
            }
        }
        return -1;
    }

    bool isEquilibrium(string str){
        vector<int> freq(10, 0);
        for (char c: str) {
            freq[c-'0']++;
        }
        for (int i = 0; i < 10; ++i) {
            if (freq[i] != 0 && freq[i] != i)
                return false;
        }
        return true;
    }
};