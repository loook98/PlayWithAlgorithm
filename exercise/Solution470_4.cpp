#include <bits/stdc++.h>

using namespace std;

// The rand7() API is already defined for you.
 int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        //用rand7()生成2位的7进制数（转为10进制存储）， 这个范围[0,48]内的数出现的概率是相等的
        int random7baseNum = (7 * (rand7()-1) + (rand7()-1));

        //再拒绝采样
        while ( !(random7baseNum >= 1 && random7baseNum <= 40)){
            random7baseNum = (7 * (rand7()-1) + (rand7()-1));
        }
        return random7baseNum % 10 + 1;
    }
};