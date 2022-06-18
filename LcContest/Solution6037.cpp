#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            int maxIndex = i;
            for (int j = i+1; j < n; ++j) {
                if (((s[i]-'0') & 1) == 1){ //奇数
                    if (((s[j] - '0') & 1) == 1){
                        if ((s[j]-'0') > s[maxIndex] - '0')
                            maxIndex = j;
                    }
                } else{
                    if (((s[j] - '0') & 1) == 0){
                        if ((s[j]-'0') > s[maxIndex] - '0')
                            maxIndex = j;
                    }
                }
            }
            swap(s[i],s[maxIndex]);
        }

        return stoi(s);
    }
};
