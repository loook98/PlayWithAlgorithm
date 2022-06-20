#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0)
            return 0;
        if (k == 0){
            if (num % 10 == 0)
                return 1;
            else
                return -1;
        }

        int numOfK = 1;
        while (k * numOfK <= num){
            if ((num - k * numOfK) % 10 == 0)
                return numOfK;
            numOfK++;
        }

        return -1;
    }
};