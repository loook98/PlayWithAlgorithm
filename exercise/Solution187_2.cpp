#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> ret;
        if (s.size() < 10){
            vector<string> r(ret.begin(), ret.end());
            return r;
        }
        unordered_map<int, long long> map;
        map['A'] = 1;
        map['C'] = 2;
        map['G'] = 3;
        map['T'] = 4;
        //先初始化一个长度为9的字符串的哈希值
        long long hash = 0;
        int i;
        for (i = 0; i < 9; ++i) {
            hash = hash * 10 + map[s[i]];
        }

        int n = s.size();
        unordered_set<long long> set;
        for (; i < n; ++i) {
            //此时当前元素加上前边长度为9的字符串，为10长度的串，计算其hash
            hash = hash * 10 + map[s[i]];
            if (set.count(hash)) {//不用处理hash冲突，因为这里的每个哈希值都是对应的二进制值，并且没有取余
                ret.insert(s.substr(i - 9, 10));
            } else {
                set.insert(hash);
            }

            //去掉头部元素，变成一个9位的字符串，得到它的hash值
            hash = hash - map[s[i - 9]] * 1000000000;
        }
        vector<string> retV(ret.begin(), ret.end());
        return retV;
    }
};