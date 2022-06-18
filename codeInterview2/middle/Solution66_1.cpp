#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int> &a) {
        int n = a.size();
        vector<int> preMulti(n), postMulti(n);


        for (int i = 0; i < n; ++i) {
            preMulti[i] = a[i] * (i > 0 ? preMulti[i - 1] : 1);
        }

        for (int j = n - 1; j >= 0; --j) {
            postMulti[j] = a[j] * (j < n - 1 ? postMulti[j + 1] : 1);
        }

        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = (i - 1 >= 0 ? preMulti[i - 1] : 1) *
                     (i + 1 < n ? postMulti[i + 1] : 1);
        }
        return res;
    }
};