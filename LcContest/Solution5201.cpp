#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int wateringPlants(vector<int> &plants, int capacity) {
        int n = plants.size();
        int i = 0, steps = 0, remainWater = capacity;
        while (i < n) {
            if (remainWater >= plants[i]) {
                remainWater -= plants[i];
                i++;
                steps++;
            } else {
                steps += i + (i + 1);
                remainWater = capacity - plants[i];
                i++;
            }
        }

        return steps;
    }
};