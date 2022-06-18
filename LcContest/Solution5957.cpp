#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ret = "";
        int sIndex = 0, spaceIndex = 0;
        if (spaces[0] == 0){
            ret.push_back(' ');
            spaceIndex++;
        }

        while (sIndex < s.size()){
            ret.push_back(s[sIndex]);
            if (spaceIndex < spaces.size() && sIndex == spaces[spaceIndex] - 1){
                ret.push_back(' ');
                spaceIndex++;
            }
            sIndex++;
        }
        return ret;
    }
};