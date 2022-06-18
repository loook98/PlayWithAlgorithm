#include <bits/stdc++.h>

using namespace std;
//单个运行不会超时，提交会超时，可能总体时间会超时
class Solution {
public:
    struct cmp{
        bool operator()(const pair<char,int>& p1, const pair<char,int>& p2){
            return p1.second < p2.second;
        }
    };
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0)
            return tasks.size();

        vector<int> nextPos(26);//记录每个任务最前的下一个位置
        unordered_map<char, int> freq; //各个任务的初始次数
        for (char task : tasks) {
            freq[task]++;
        }

        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq;
        for (auto fq : freq) {
            pq.push(fq);
        }

        int res = 0;
        while (pq.top().second != 0){
            //找出堆顶当前不能工作的任务
            vector<pair<char, int>> waiting;
            while (!pq.empty() && res < nextPos[pq.top().first - 'A']){
                auto p = pq.top();
                pq.pop();
                waiting.push_back(p);
            }

            //处理堆顶剩下的可以工作的任务
            if (pq.empty()){
                res++;
            } else{
                auto pair = pq.top();
                pq.pop();
                pair.second--;
                nextPos[pair.first - 'A'] = res + n + 1;
                pq.push(pair);
                res++;
            }

            //将之前不能工作的任务重新入堆
            for (auto w : waiting) {
                pq.push(w);
            }
        }
        return res;
    }
};