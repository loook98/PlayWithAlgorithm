#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> adjacency(numCourses, vector<int>(numCourses, 0));
        vector<int> inDegrees(numCourses, 0);

        for (auto edge: prerequisites) {
            inDegrees[edge[1]]++;
            adjacency[edge[0]][edge[1]] = 1;
        }

        queue<int> queue; //存放当前入度为0的节点
        for (int i = 0; i < numCourses; ++i) { //先将入度为0的节点入队
            if (inDegrees[i] == 0)
                queue.push(i);
        }
        int n = numCourses;
        while (!queue.empty()) {
            int noInNode = queue.front();
            queue.pop();

            for (int i = 0; i < numCourses; ++i) {
                if (adjacency[noInNode][i] == 1){
                    if (--inDegrees[i] == 0)
                        queue.push(i);
                }
            }
            n--;
        }
        return n == 0;
    }
};