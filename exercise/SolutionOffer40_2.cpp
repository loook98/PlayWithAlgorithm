#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k) {
        quickSort(arr, 0, arr.size() - 1, k);

        return {arr.begin(), arr.begin() + k};
    }

    int partition(vector<int> &arr, int l, int r) {
        int randomIndex = l + rand() % (r - l + 1);
        swap(arr[l], arr[randomIndex]);

        //(0,j]为<= arr[l]的数， (j,i)为>arr[l]的数
        int j = l, i = l + 1;
        while (i <= r) {
            if (arr[i] > arr[l]) {
                i++;
            } else {
                j++;
                swap(arr[j], arr[i]);
                i++;
            }
        }

        swap(arr[l], arr[j]);
        return j;
    }

    void quickSort(vector<int> &arr, int l, int r, int k) {
        if (l >= r)
            return;

        int p = partition(arr, l, r);
        if (k - 1 == p)
            return;
        else if (k - 1 < p)
            quickSort(arr, l, p - 1, k);
        else
            quickSort(arr, p + 1, r, k);
    }
};