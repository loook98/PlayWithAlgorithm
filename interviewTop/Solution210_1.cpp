#include <bits/stdc++.h>

using namespace std;

//利用后序遍历的顺序翻转后是拓扑排序的结果来求解
class Solution {
public:
    vector<bool> onPath;
    vector<bool> visited;
    bool hasCycle = false;
    vector<int> postOrder;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>> graph = buildGraph(numCourses, prerequisites);
        onPath = vector<bool>(numCourses);
        visited = vector<bool>(numCourses);

        for (int i = 0; i < numCourses; ++i) {
            traverse(graph, i);
        }

        if (hasCycle){
            vector<int> emptyRet;
            return emptyRet;
        } else{
            reverse(postOrder.begin(), postOrder.end());//翻转后序遍历的结果就是拓扑排序的结果
            return postOrder;
        }
    }
    //后续遍历
    void traverse(const vector<list<int>>& graph, int s){
        if (onPath[s]){
            hasCycle = true;
            return;
        }
        if (visited[s] || hasCycle)
            return;

        visited[s] = true;
        onPath[s] = true;
        for (auto edgeNode : graph[s]) {
            traverse(graph, edgeNode);
        }
        postOrder.emplace_back(s); //相当于后续遍历的访问操作
        onPath[s] = false;
    }

    vector<list<int>> buildGraph(int numsCourses, const vector<vector<int>>& prerequisites){
        vector<list<int>> graph(numsCourses);
        for (auto prerequisite : prerequisites)
            // 边A--->B 指定为：要学A才能学B的话，按给的prerequisites的语意的话应该是 prerequisite[1]-->prerequisite[0]
            graph[prerequisite[1]].emplace_back(prerequisite[0]);
        return graph;
    }
};