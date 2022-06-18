#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacency(numCourses);
        vector<int> inDegree(numCourses);

        //初始化邻接表和入度数组
        for (auto &edge : prerequisites) {
            adjacency[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
        }

        queue<int> zeroIn;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0)
                zeroIn.push(i);
        }

        int count = 0 ;//记录已经选过的课的个数
        while (!zeroIn.empty()){
            int node = zeroIn.front();
            zeroIn.pop();
            count++;
            for (int i = 0; i < adjacency[node].size(); ++i) {
                inDegree[adjacency[node][i]]--;
                if (inDegree[adjacency[node][i]] == 0)
                    zeroIn.push(adjacency[node][i]);
            }
        }

        return count == numCourses;
    }
};