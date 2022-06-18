#include <bits/stdc++.h>

using namespace std;

// The rand7() API is already defined for you.
int rand7();
// @return a random integer in the range 1 to 7

//思路：
//两位的7进制数可以表示[0...48]之间的数。
//所以我们用rand7来生成第1位和第二位。
//再拒绝[0]、和[11,48]之间的数，就可以生成[1,10]之间的随机数了
class Solution {
public:
    int rand10() {
        while (true){
            int rand0_48 = (rand7() - 1) * 7 + (rand7() - 1);
            if (rand0_48 >= 1 && rand0_48 <= 10)
                return rand0_48;
        }
    }
};

//【有问题】
//虽然能过，但是没有效率不高。
//应该[0,40]范围能就可以跳出循环了，只要把这个[0,40]范围内的值%10 + 1就可以返回了。