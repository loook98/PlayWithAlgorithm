#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //邻接表
        vector<vector<int>> adjacency(numCourses);
        //记录入度
        vector<int> inDegree(numCourses, 0);

        //初始化
        for (auto &pre: prerequisites) {
            adjacency[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }

        //存储入度为0的节点
        queue<int> zeroIn;
        int zeroNum = 0;//记录入度为0的节点古树
        for (int i = 0; i < inDegree.size(); ++i) {
            if (inDegree[i] == 0){
                zeroIn.push(i);
                zeroNum++;
            }
        }

        while (!zeroIn.empty()){
            int zeroInNode = zeroIn.front();
            zeroIn.pop();

            for (int edgeNode: adjacency[zeroInNode]) {
                inDegree[edgeNode]--;
                if (inDegree[edgeNode] == 0){
                    zeroIn.push(edgeNode);
                    zeroNum++;
                }
            }
        }

        return zeroNum == numCourses;
    }
};