#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int endIndex;

    vector<int> getLeastNumbers(vector<int> &arr, int k) {
        endIndex = k - 1;
        quickSort(arr, 0, arr.size() - 1);

        vector<int> res(arr.begin(), arr.begin() + k);
        return res;
    }

    void quickSort(vector<int> &arr, int l, int r) {
        if (l >= r)
            return;

        int pos = partition(arr, l, r);
        if (pos == endIndex)
            return;
        else if (endIndex < pos)
            quickSort(arr, l, pos - 1);
        else
            quickSort(arr, pos + 1, r);
    }

    int partition(vector<int> &arr, int l, int r) {
        int randIndex = l + (rand() % (r - l + 1));
        swap(arr[l], arr[randIndex]);

        int ltEt = l, i = l + 1;
        while (i <= r) {
            if (arr[i] <= arr[l]) {
                ltEt++;
                swap(arr[ltEt], arr[i]);
                i++;
            } else {
                i++;
            }
        }
        swap(arr[l], arr[ltEt]);
        return ltEt;
    }
};