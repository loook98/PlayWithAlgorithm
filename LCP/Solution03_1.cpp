#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        unordered_set<unsigned long long>  obstacle_handled;
        for (auto obstacle : obstacles) {
            unsigned long long x = obstacle[0];
            unsigned long long y = obstacle[1];
            x <<= 30;
            obstacle_handled.insert(x|y);
        }

        unsigned long long xIndex = 0, yIndex = 0;
        while (true){
            for (char comm : command) {
                if (xIndex == x && yIndex == y)
                    return true;
                if (xIndex > x || yIndex > y)
                    return false;

                if (comm == 'U'){
                    yIndex++;
                } else{
                    xIndex++;
                }

                if (obstacle_handled.count((xIndex << 30) | yIndex))
                    return false;
            }
        }
    }
};