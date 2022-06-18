#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int convertTime(string current, string correct) {
        auto cur = time2int(current);
        auto cor = time2int(correct);

        int Dif = cor - cur;
        int res = 0;
        res += Dif / 60;
        Dif %= 60;
        res += Dif / 15;
        Dif %= 15;
        res += Dif /5;
        Dif %= 5;
        res += Dif;
        return res;
    }

    int time2int(const string& s){
        int m = 0 , h = 0;
        int i = 0;
        for(i = 0; i < 2; i++){
            h = h*10 + (s[i]-'0');
        }
        for (i = 3; i < 5; ++i) {
            m = m*10 + (s[i]-'0');
        }

        return h*60+m;
    }
};

