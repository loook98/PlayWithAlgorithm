#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> res = {-1, -1};
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                int resLeft = mid, resRight = mid; //最终结果(resLeft, resRight)
                while (resLeft >= 0 && nums[resLeft] == target)
                    resLeft--;
                while (resRight < n && nums[resRight] == target)
                    resRight++;

                res[0] = resLeft + 1;
                res[1] = resRight - 1;
                return res;
            }

            if (target < nums[mid])
                r = mid - 1;//这里r要=mid-1而不是mid，否则在最后l==r且target小于这个值时会死循环
            else
                l = mid + 1;
        }
        return res;
    }
};