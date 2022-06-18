#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int res = 0;
        for (string str : patterns) {
            string::size_type index;
            index = word.find(str);
            if (index != string::npos)
                res++;
        }
        return res;
    }
};