#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int aIndex = a.size() - 1, bIndex = b.size() - 1;
        string ret;
        for( ; aIndex >= 0 && bIndex >= 0; --aIndex, --bIndex){
            int aNum = a[aIndex] - '0', bNum = b[bIndex] - '0';
            int sum =  aNum + bNum + carry;
            ret.insert(ret.begin(), ((sum%2) + '0'));
            carry = sum / 2;
        }
        while (aIndex >= 0){
            int sum = a[aIndex] - '0' + carry;
            ret.insert(ret.begin(), ((sum%2) + '0'));
            carry = sum / 2;
            aIndex--;
        }
        while (bIndex >= 0){
            int sum = b[bIndex] - '0' + carry;
            ret.insert(ret.begin(), static_cast<char>((sum%2) + '0'));
            carry = sum / 2;
            bIndex--;
        }
        if (carry == 1)
            ret.insert(ret.begin(), '1');
        return ret;
    }
};