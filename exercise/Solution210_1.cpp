#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>> adjacency(numCourses);
        vector<int> inDegree(numCourses);

        for (auto &rvsEdge : prerequisites) {
            adjacency[rvsEdge[1]].push_back(rvsEdge[0]);
            inDegree[rvsEdge[0]]++;
        }

        queue<int> zeroIn;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0)
                zeroIn.push(i);
        }

        vector<int> res;
        while (!zeroIn.empty()){
            int node = zeroIn.front();
            zeroIn.pop();
            res.push_back(node);
            //更新指向的节点的入度
            for (auto &index : adjacency[node]) {
                inDegree[index]--;
                if (inDegree[index] == 0)
                    zeroIn.push(index);
            }
        }

        return res.size() == numCourses ? res : vector<int>();
    }
};