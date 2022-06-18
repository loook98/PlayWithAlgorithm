#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000")
            return 0;

        //遇到deadends需要停止，遇到visited也要停止，故将两者合并为ends
        unordered_set<string> ends;
        for (string deadend : deadends) {
            ends.insert(deadend);
        }

        string s = "0000";
        if (ends.count(s))
            return -1;
        queue<string> queue;
        queue.push(s);
        ends.insert(s);
        int step = 0;
        while (!queue.empty()){
            int sz = queue.size();

            string tmp;
            step++;
            for (int i = 0; i < sz; ++i) {
                tmp = queue.front();
                queue.pop();

                for (int j = 0; j < 4; ++j) {
                    string p1 = plusOne(tmp, j);
                    if (p1 == target)
                        return step;
                    if (!ends.count(p1)){
                        queue.push(p1);
                        ends.insert(p1);
                    }


                    string s1 = subOne(tmp, j);
                    if (s1 == target)
                        return step;
                    if (!ends.count(s1)){
                        queue.push(s1);
                        ends.insert(s1);
                    }

                }
            }
        }
        return -1;
    }

    //s[i]+1
    string plusOne(const string& s, int i){
        if (i >= s.size())
            cout << s << " " << i <<" error" ;

        string r = s;
        if (r[i] == '9')
            r[i] = '0';
        else
            r[i]++;

        return r;
    }
    //s[i]-1
    string subOne(const string& s,int i){
        if (i >= s.size())
            cout << "error";

        string r = s;
        if (r[i] == '0')
            r[i] = '9';
        else
            r[i]--;

        return r;
    }
};