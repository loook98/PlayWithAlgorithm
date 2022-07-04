#include <bits/stdc++.h>

using namespace std;

//对[1,x]区间进行二分，太慢。
class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, r = x;

        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (mid * mid == x)
                return mid;
            else if (mid * mid < x) {
                if ((mid + 1) * (mid + 1) > x)
                    return mid;
                else
                    l = mid + 1;
            } else{ // >
                if ((mid - 1) * (mid - 1) < x)
                    return mid - 1;
                else
                    r = mid - 1;
            }
        }

        throw exception();
    }
};