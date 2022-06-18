#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> aux(n1 + n2, 0);
        int auxIndex = 0, index1 = 0, index2 = 0;
        while (index1 < n1 && index2 < n2) {
            if (nums1[index1] < nums2[index2])
                aux[auxIndex++] = nums1[index1++];
            else
                aux[auxIndex++] = nums2[index2++];
        }
        while (index1 < n1)
            aux[auxIndex++] = nums1[index1++];
        while (index2 < n2)
            aux[auxIndex++] = nums2[index2++];

        int n = aux.size();
        if ((n & 1) == 1)
            return aux[(n - 1) / 2];
        else
            return (aux[(n - 1) / 2] + aux[(n - 1) / 2 + 1]) / 2.0;
    }
};
