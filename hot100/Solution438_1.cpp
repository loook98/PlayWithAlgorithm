#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.size() < p.size())
            return res;

        vector<int> freq(26, 0);
        for (char i : p){
            freq[i - 'a']++;
        }

        int l = 0, r = 0;
        vector<int> freqWindow(26, 0);
        for (r = 0; r < p.size(); ++r)
            freqWindow[s[r] - 'a']++;
        r--;


        while (r < s.size()){
            if (isEqual(freq, freqWindow))
                res.push_back(l);

            freqWindow[s[l] - 'a']--;
            l++;
            r++;
            if (r == s.size())
                break;
            freqWindow[s[r] - 'a']++;
        }
        return res;
    }

    bool isEqual(vector<int>& f1, vector<int>& f2){
        assert( (f1.size() == 26) &&(f2.size() == 26));
        for (int i = 0; i < 26; ++i) {
            if (f1[i] != f2[i])
                return false;
        }
        return true;
    }
};
