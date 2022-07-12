#include <bits/stdc++.h>

using namespace std;

//先翻转整个字符串，然后再依次翻转每个单词
class Solution {
public:
    string reverseWords(string s) {
        //翻转之前先去除前导和后置空格
        while (!s.empty() && s[0] == ' '){
            s.erase(0, 1);
        }
        while (!s.empty()){
            int n = s.size();
            if (s[n-1] != ' ')
                break;
            s.erase(n-1, 1);
        }

        //翻转整个字符串
        int l = 0, r = s.size() - 1;
        while (l < r){
            swap(s[l], s[r]);
            l++;
            r--;
        }

        //按顺序翻转各个单词
        int i = 0;
        while (i < s.size()){
            //找到单词的左右边界
            int start = i, end = i;
            while (end + 1 < s.size() && s[end + 1] != ' ')
                end++;
            i = end + 1;
            //翻转单词
            while (start < end){
                swap(s[start], s[end]);
                start++;
                end--;
            }

            //将单词间的空格只留一个
            int spaceNum = 0;
            while (i < s.size() && s[i] == ' '){
                if (spaceNum >= 1)
                    s.erase(i, 1);
                else
                    i++;
                spaceNum++;
            }

        }

        return s;
    }
};