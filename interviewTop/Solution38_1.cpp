#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string countAndSay = "1";
        for (int i = 2; i <= n; ++i) {
            string temp;
            int count = 0;
            for (int j = 0; j < countAndSay.size(); ++j) {
                count++;
                if ( j == countAndSay.size() - 1 || countAndSay[j+1] != countAndSay[j]){
                    temp += to_string(count);
                    temp += countAndSay[j];
                    count = 0;
                }
            }
            countAndSay = temp;
        }
        return countAndSay;
    }
};