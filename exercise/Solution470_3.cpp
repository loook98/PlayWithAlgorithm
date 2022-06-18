#include <bits/stdc++.h>

using namespace std;

// The rand7() API is already defined for you.
int rand7();
// @return a random integer in the range 1 to 7

//思路：
//两位的7进制数可以表示[0...48]之间的数。
//所以我们用rand7来生成第1位和第二位,就能生成[0,48]之间的随机数。
//再拒绝[0]和[41,48]之间的数，将[1,40]之间的数%10 + 1,就可生成[1,10]之间的随机数
class Solution {
public:
    int rand10() {
        while (true){
            int rand0_48 = (rand7() - 1) * 7 + (rand7() - 1);
            if (rand0_48 >= 1 && rand0_48 <= 40)
                return rand0_48 % 10 + 1;
        }
    }
};