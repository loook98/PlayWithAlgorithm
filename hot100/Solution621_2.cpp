#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool comp(const pair<char, int>& p1, const pair<char, int>& p2){
        return p1.second < p2.second;
    }

    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0)
            return tasks.size();

        vector<int> nextPos(26);//记录每个任务最前的下一个位置
        unordered_map<char, int> freq; //各个任务的初始次数
        for (char task : tasks) {
            freq[task]++;
        }

        vector<pair<char,int>> vecFreq;
        for (auto f : freq) {
            vecFreq.emplace_back(f);
        }
        sort(vecFreq.begin(), vecFreq.end(),comp);

        int res = 0;
        int taskNum = tasks.size();
        while (taskNum != 0){
            int i;
            for (i = vecFreq.size() - 1; i >= 0; --i) {
                if (vecFreq[i].second > 0 && res >= nextPos[vecFreq[i].first - 'A'])
                    break;
            }

            if (i >= 0){
                nextPos[vecFreq[i].first - 'A'] = res + n + 1;
                res++;
                --vecFreq[i].second;
                taskNum--;
                //保证vecFreq按任务的个数由小到大排序
                for (int j = i; j - 1 >= 0; --j) {
                    if (vecFreq[j-1].second > vecFreq[j].second)
                        swap(vecFreq[j-1], vecFreq[j]);
                }
            } else{
                res++;
            }
        }
        return res;
    }
};