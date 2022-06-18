#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long numeratorL = numerator;
        long long denominatorL = denominator;

        if (numeratorL % denominatorL == 0)
            return to_string(numeratorL / denominatorL);

        if (numeratorL == 0)
            return "0";

        unordered_map<long long, int> remainAndIndex;
        string res;
        if (numeratorL * denominatorL < 0)
            res.push_back('-');
        numeratorL = abs(numeratorL);
        denominatorL = abs(denominatorL);

        long long remain = numeratorL % denominatorL;
        res += to_string(numeratorL / denominatorL);
        res.push_back('.');
        remainAndIndex.insert({remain, res.size() - 1});

        while (remain != 0) {
            remain *= 10;
            res += to_string(remain / denominatorL);
            remain = remain % denominatorL;
            if (remainAndIndex.count(remain)){
                string loop = res.substr(remainAndIndex[remain] + 1,
                                         res.size() - (remainAndIndex[remain] + 1));
                string beforeLoop = res.substr(0, remainAndIndex[remain] + 1);
                beforeLoop.push_back('(');
                beforeLoop += loop;
                beforeLoop.push_back(')');
                return beforeLoop;
            } else{
                remainAndIndex.insert({remain, res.size() - 1});
            }
        }
        return res;
    }
};