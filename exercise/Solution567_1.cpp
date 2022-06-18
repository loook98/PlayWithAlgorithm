#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2)
            return false;

        unordered_map<char,int> needs, window;
        for (char c : s1) {
            needs[c]++;
        }

        int left = 0, right = -1;
        int valid = 0;
        while (right < n2){
            right++;
            char c1 = s2[right];
            if (needs.count(c1)){
                window[c1]++;
                if (window[c1] == needs[c1])
                    valid++;
            }

            while (right - left + 1 == n1){
                if (valid == needs.size())
                    return true;

                char c2 = s2[left];
                left++;
                if (needs.count(c2)){
                    if (window[c2] == needs[c2])
                        valid--;
                    window[c2]--;
                }
            }
        }
        return false;
    }
};