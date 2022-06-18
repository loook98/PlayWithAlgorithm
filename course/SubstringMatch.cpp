#include <bits/stdc++.h>

using namespace std;

class SubstringMatch {

public:
    //在s中寻找t，并返回匹配的第一个索引i； 如果没找到，返回-1
    static int bruteforce(string s, string t) {
        if (s.size() < t.size())
            return -1;

        for (int i = 0; i + t.size() - 1 < s.size(); ++i) {
            int j = 0;
            for (; j < t.size(); ++j) {
                if (s[i + j] != t[j])
                    break;
            }
            if (j == t.size())
                return i;
        }
        return -1;
    }

    //在s中寻找t，并返回匹配的第一个索引i； 如果没找到，返回-1
    static int rabinKarp(string s, string t) {
        if (s.size() < t.size())
            return -1;
        if (t.empty())
            return 0;

        //计算t的hash值
        long long tHash = 0, MOD = 1e9 + 7, B = 256;
        for (int i = 0; i < t.size(); ++i) {
            tHash = (tHash * B + t[i]) % MOD;
        }


        long long hash = 0, P = 1; // P为长度为t.size()的字符串最高位的权值
        for (int i = 0; i < t.size() - 1; ++i) {
            P = (P * B) % MOD;
        }
        //先初始化一个长度为t.size()-1的字符串的哈希值
        for (int i = 0; i < t.size() - 1; ++i) {
            hash = (hash * B + s[i]) % MOD;
        }

        for (int i = t.size() - 1; i < s.size(); ++i) {
            //此时当前元素加上前边长度为t.size()-1的字符串，为t.size()长度的串，计算其hash
            hash = (hash * B + s[i]) % MOD;
            if (hash == tHash && strEqual(s, i - t.size() + 1, t)) {
                return i - (t.size() - 1);
            }

            //去掉头部元素，变成一个t.size()-1位的字符串，得到它的hash值
            hash = (hash - (s[i - t.size() + 1] * P) % MOD + MOD) % MOD;
        }
        return -1;
    }

    //判断s字符串从l处开始长度为t.size()的字符串是否和t字符串相等。是在防止hash碰撞的时候用于
    static bool strEqual(string s, int l, string t){
        for (int i = 0; i < t.size(); ++i) {
            if (s[l+i] != t[i])
                return false;
        }
        return true;
    }
};