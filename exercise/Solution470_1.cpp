#include <bits/stdc++.h>

using namespace std;

// The rand7() API is already defined for you.
 int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while (true){
            //利用生成k进制的数，来生成等概率的0~k^n-1之间的数。
            //本题：利用生成7进制的数，来生成等概率的0~7^2-1即0~48之间的数。
            int randomIn0_48 = (rand7()-1) * 7 + (rand7()-1);
            if (randomIn0_48 >= 1 && randomIn0_48 <= 40)
                return randomIn0_48 % 10;
        }
    }
};