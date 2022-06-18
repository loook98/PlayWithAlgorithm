#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k){
            string newS;
            int i = 0;
            while (i < s.size()){
                int val = 0;
                for (int j = 0; j < k && i < s.size(); ++j) {
                    val += s[i] - '0';
                    i++;
                }
                newS += to_string(val);
            }
            s = newS;
        }

        return s;
    }
};