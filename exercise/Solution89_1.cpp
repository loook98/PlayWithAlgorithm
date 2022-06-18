#include <bits/stdc++.h>

using namespace std;

// G(n+1) = G`(n) ∪ R`(n)
// G`(n)为G(n)中的每个元素前边添加0,因为元素前边都是0，所以G`(n)=G(n)
// R`(n)为G(n)反转后得到的R`(n)前边添加1
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res{0};
        int head = 1; //head为要往前边加的1
        for (int i = 1; i <= n; ++i) {
            for (int j = res.size() - 1; j >= 0 ; --j) {
                res.emplace_back(head + res[j]);
            }
            head <<= 1;
        }
        return res;
    }
};