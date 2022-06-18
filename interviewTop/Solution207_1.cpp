#include <bits/stdc++.h>

using namespace std;

//将课程的依赖关系构建成图，DFS进行遍历，每次DFS只要保证没有环，则表示可以学完。
class Solution {
public:
    vector<bool> onPath;
    vector<bool> visited;
    bool hasCycle = false;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>> graph = buildGraph(numCourses, prerequisites);
        onPath = vector<bool>(numCourses);
        visited = vector<bool>(numCourses);
        for (int i = 0; i < numCourses; ++i) {
            traverse(graph, i);
        }

        return !hasCycle;
    }

    void traverse(const vector<list<int>>& graph, int s){
        if (onPath[s]){ //有环
            hasCycle = true;
            return;
        }

        if (visited[s] || hasCycle)
            return;

        visited[s] = true;
        onPath[s] = true;
        for (auto node : graph[s])
            traverse(graph, node);
        onPath[s] = false;
    }

    vector<list<int>> buildGraph(int numCourses, const vector<vector<int>>& prerequisites){
        vector<list<int>> res(numCourses);
        for (const auto & prerequisite : prerequisites)
            res[prerequisite[0]].emplace_back(prerequisite[1]);

        return res;
    }
};