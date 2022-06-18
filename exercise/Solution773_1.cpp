#include <bits/stdc++.h>

using namespace std;

//BFS
class Solution {
public:
    //记录索引i位置处相邻的其他位置的索引
    vector<vector<int>> neighbor{
            {1,3},
            {0,2,4},
            {1,5},
            {0,4},
            {1,3,5},
            {2,4}
    };
    unordered_set<string> visited;

    int slidingPuzzle(vector<vector<int>>& board) {
        string status;
        //构建初始的状态字符串
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                status.push_back('0'+board[i][j]);
            }
        }

        string target = "123450";
        queue<pair<string, int>> bfsQ; //bfsQ内是<状态，步骤数>
        bfsQ.push({status,0});
        while (!bfsQ.empty()){
            auto pair = bfsQ.front();
            bfsQ.pop();
            string curStatus = pair.first;
            int steps = pair.second;

            if (curStatus == target)
                return steps;
            if (visited.count(curStatus))
                continue;
            visited.insert(curStatus);

            for (int i = 0; i < 6; ++i) {
                //找到0的位置
                if (curStatus[i] == '0'){
                    //遍历周边节点
                    for (int n : neighbor[i]) {
                        string s = curStatus;
                        swap(s[i], s[n]);
                        bfsQ.push({s, steps+1});
                    }
                    break;
                }
            }
        }
        return -1;
    }
};