#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res;
        int n = s.size();
        int i = n - 1;
        while (i >= 0){
            while (i >= 0 && s[i] == ' ')
                i--;

            if (i < 0)
                break;

            stack<char> tmp;
            while (i >= 0 && s[i] != ' '){
                tmp.push(s[i]);
                i--;
            }

            while (!tmp.empty()){
                res += tmp.top();
                tmp.pop();
            }

            res += ' ';
        }
        res.pop_back();
        return res;
    }
};

int main(){
    string s = "  hello world";
    Solution().reverseWords(s);
    return 0;
}