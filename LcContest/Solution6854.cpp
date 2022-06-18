#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int>& pro1, vector<int>& pro2){
    if (pro1[0] == pro2[0])
        return pro1[1] < pro2[1];
    return pro1[0] > pro2[0];
}

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(),cmp);

        int maxdef = 0, res = 0;
        for (auto p : properties){
            if (p[1] < maxdef)
                res++;
            else
                maxdef = p[1];
        }
        return res;
    }
};