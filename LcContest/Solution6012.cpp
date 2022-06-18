#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countEven(int num) {
        int ret = 0;
        for (int i = 1; i <= num; ++i) {
            if (isEven(i))
                ret++;
        }
        return ret;
    }
    
    bool isEven(int num){
        int sum = 0;
        while (num > 0){
            sum += num % 10;
            num /= 10;
        }
        
        return sum % 2 == 0;
    }
};