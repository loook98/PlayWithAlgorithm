#include <bits/stdc++.h>

using namespace std;

class BucketSort {
public:
    static void sort(vector<int> &arr, int B) { //B为桶排序的桶的个数
        if (B <= 1)
            throw runtime_error("Bucket number 'B' must be greater than 1!");
        vector<int> temp(arr.size());
        sort(arr, 0, arr.size() - 1, B, temp);
    }

    //MSD思路的桶排序
    static void sort(vector<int> &arr, int left, int right, int B, vector<int> &temp) {
        if (left >= right)
            return;

        int minv = INT32_MAX, maxv = INT32_MIN;
        for (int i = left; i <= right; ++i) {
            minv = min(minv, arr[i]);
            maxv = max(maxv, arr[i]);
        }
        if (maxv == minv) return; //区间内所有元素都相等

        //注意：这里要向上取整
        int d = (maxv - minv + 1) / B + ((maxv - minv + 1) % B > 0 ? 1 : 0); //d为每个桶的最大元素个数.

        vector<int> cnt(B);
        vector<int> index(B + 1);

        //计数
        for (int i = left; i <= right; ++i)
            cnt[(arr[i] - minv) / d]++;
        for (int i = 0; i < B; ++i)
            index[i + 1] = index[i] + cnt[i];

        //排序
        for (int i = left; i <= right; ++i) {
            int p = (arr[i] - minv) / d; //桶号
            temp[left + index[p]] = arr[i];
            index[p]++;
        }
        for (int i = left; i <= right; ++i)
            arr[i] = temp[i];

        //继续递归下去
        sort(arr, left, left + index[0] - 1, B, temp);
        for (int i = 0; i < B; ++i)
            sort(arr, left + index[i] - 1, left + index[i + 1] - 1, B, temp);
    }

    //更简单的桶排序（不用递归）
    static void sort2(vector<int> arr, int c) {//c为每个桶中最大元素数
        if (c <= 0)
            throw runtime_error("c must be > 0");

        int B = arr.size() / c + (arr.size() % c > 0 ? 1 : 0); //B是桶的个数，需要向上取整

        vector<list<int>> buckets(B);

        int minv = INT32_MAX, maxv = INT32_MIN;
        for (auto e : arr) {
            minv = min(minv, e);
            maxv = max(maxv, e);
        }
        if (minv == maxv) return;

        //放入桶中
        for (auto e : arr)
            buckets[(e - minv) / c].emplace_back(e);

        //对各个桶中的元素进行排序
        for (auto bucket: buckets)
            bucket.sort();

        //依次把桶中元素，放回arr
        int index = 0;
        for (int i = 0; i < B; ++i)
            for (auto e: buckets[i])
                arr[index++] = e;
    }
};