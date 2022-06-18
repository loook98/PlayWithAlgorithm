#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        int sn = s.size(), pn = p.size();
        if (sn < pn)
            return ret;

        unordered_map<char, int> needs, window;
        for (char c : p) {
            needs[c]++;
        }

        int left = 0, right = -1;
        int valid = 0;
        while (right < sn - 1){
            right++;
            char c1 = s[right];
            if (needs.count(c1)){
                window[c1]++;
                if (window[c1] == needs[c1])
                    valid++;
            }

            while (right - left + 1 == pn){
                if (valid == needs.size()){
                    ret.push_back(left);
                }

                char c2 = s[left];
                left++;
                if (needs.count(c2)){
                    if (window[c2] == needs[c2])
                        valid--;
                    window[c2]--;
                }
            }
        }
        return ret;
    }
};