#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.size();
        int count = 0;
        for (auto c : s) {
            if (c == letter)
                count++;
        }

        double rate = (double)count / n;
        rate *= 100;
        return rate;
    }
};