#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int convertTime(string current, string correct) {
        queue<pair<int,int>> q;
        q.push({time2int(current),0});

        int cor = time2int(correct);
        while (!q.empty()){
            auto pair = q.front();
            q.pop();
            int cur = pair.first;
            int steps = pair.second;

            if (cur == cor)
                return steps;

            vector<int> add{1,5,15,60};
            for (int i = 0; i < 4; ++i) {
                q.push({cur+add[i], steps + 1});
            }
        }
        return -1;
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

        return h * 60 + m;
    }
};