#include <bits/stdc++.h>

using namespace std;

//先反转整个字符串
//然后再依次反转各个单词
class Solution {
public:
    string reverseWords(string s) {
        //先去掉前导空格和尾随空格
        int endOfPreSpace;
        for (endOfPreSpace = 0; endOfPreSpace < s.size(); ++endOfPreSpace) {
            if (s[endOfPreSpace] != ' ')
                break;
        }
        int startOfPostSpace;
        for (startOfPostSpace = s.size() - 1; startOfPostSpace >= 0; --startOfPostSpace) {
            if (s[startOfPostSpace] != ' ')
                break;
        }
        if (endOfPreSpace > startOfPostSpace)
            return "";
        if(startOfPostSpace != s.size() - 1){
            s.erase(s.begin() + startOfPostSpace + 1, s.end());
        }
        if (endOfPreSpace != 0) {
            s.erase(s.begin(), s.begin() + endOfPreSpace);
        }

        //反转整个字符串
        reverse(s.begin(), s.end());

        //再依次翻转各个单词
        s.push_back(' '); //加个空格方便处理
        int start = 0, end = 0;
        while (end < s.size()) {
            while (s[end] != ' ')
                end++;
            //删除两个单词间的多余空格
            while (end + 1 < s.size() && s[end + 1] == ' ')
                s.erase(s.begin() + end + 1);

            int l = start, r = end - 1;
            while (l < r) {
                swap(s[l], s[r]);
                l++;
                r--;
            }

            start = end + 1;
            end++;
        }
        s.erase(s.end() - 1); //删除前边加的空格
        return s;
    }
};

int main(){
    Solution().reverseWords("F R  I   E    N     D      S      ");
}