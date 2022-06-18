#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int reload = 0;
        int n = plants.size();
        int alice = 0, bob  = n-1;
        int remainWaterA = capacityA, remainWaterB = capacityB;
        while (alice <= bob){
            if (alice == bob){
                if (remainWaterA > remainWaterB){
                    if (isReloadAfterPour(remainWaterA, capacityA, plants[alice]))
                        reload++;
                } else if (remainWaterB > remainWaterA){
                    if (isReloadAfterPour(remainWaterB, capacityB, plants[bob]))
                        reload++;
                } else{
                    if (isReloadAfterPour(remainWaterA, capacityA, plants[alice]))
                        reload++;
                }
                break;
            }

            if (isReloadAfterPour(remainWaterA, capacityA, plants[alice]))
                reload++;
            alice++;
            if (isReloadAfterPour(remainWaterB, capacityB, plants[bob]))
                reload++;
            bob--;
        }

        return reload;
    }

    bool isReloadAfterPour(int &remainWater, int capacity, int plant){
        if (remainWater >= plant){
            remainWater -= plant;
            return false;
        } else{
            remainWater = capacity - plant;
            return true;
        }
    }
};