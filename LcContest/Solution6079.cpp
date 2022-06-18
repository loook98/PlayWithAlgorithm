#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        int disCnt = 100 - discount;

        istringstream iss(sentence);
        string res;
        string temp;
        while (iss >> temp) {
            int n = temp.size();
            if (temp[0] == '$' && n > 1) {
                long long price = 0;
                int i = 1;
                for (; i < n; ++i) {
                    if (!isdigit(temp[i])) {
                        break;
                    } else {
                        price = price * 10 + temp[i] - '0';
                    }
                }
                if (i == n) {
                    long long discounted = price * disCnt;
                    res += "$";
                    string noPoint = to_string(discounted);
                    if (discounted != 0) {
                        if (noPoint.size() == 2 || noPoint.size() == 1)
                            res += "0";
                        if (noPoint.size() == 1)
                            noPoint.insert(0, "0");

                        noPoint.insert(noPoint.size() - 2, ".");
                        res += noPoint;
                    } else {
                        res += "0.00";
                    }

                    res += " ";
                } else {
                    res += temp;
                    res += " ";
                }
            } else {
                res += temp;
                res += " ";
            }
        }

        //删除最后空格
        res.pop_back();
        return res;
    }
};

//"$2$3 $10 $100 $1 200 $33 33$ $$ $99 $99999 $9999999999"
//99