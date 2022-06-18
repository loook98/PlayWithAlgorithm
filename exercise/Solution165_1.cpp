#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size(), n2 = version2.size();
        int index1 = 0, index2 = 0;

        //判断两个版本号公共的部分
        while (index1 < n1 && index2 < n2) {
            if (version1[index1] == '.') {
                index1++;
            }

            if (version2[index2] == '.') {
                index2++;
            }

            int num1 = 0, num2 = 0;
            while (index1 < n1 && version1[index1] != '.') {
                num1 = num1 * 10 + (version1[index1] - '0');
                index1++;
            }
            while (index2 < n2 && version2[index2] != '.') {
                num2 = num2 * 10 + (version2[index2] - '0');
                index2++;
            }

            if (num1 > num2)
                return 1;
            else if (num1 < num2)
                return -1;
        }

        //判断版本后剩余的部分
        if (index1 < n1) { //如果version1还有剩余
            while (index1 < n1) {
                if (version1[index1] == '.') {
                    index1++;
                }
                int num1 = 0;
                while (index1 < n1 && version1[index1] != '.') {
                    num1 = num1 * 10 + (version1[index1] - '0');
                    index1++;
                }
                if (num1 > 0)
                    return 1;
            }

            return 0;
        } else if (index2 < n2) { //如果version2还有剩余
            while (index2 < n2) {
                if (version2[index2] == '.') {
                    index2++;
                }
                int num2 = 0;
                while (index2 < n2 && version2[index2] != '.') {
                    num2 = num2 * 10 + (version2[index2] - '0');
                    index2++;
                }
                if (num2 > 0)
                    return -1;
            }
            return 0;
        } else{ //无剩余
            return 0;
        }
    }
};