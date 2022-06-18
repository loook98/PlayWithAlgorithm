#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int pushIndex = 0;
        int popIndex = 0;

        while (pushIndex < pushed.size()){
            while (pushIndex < pushed.size() && popIndex < popped.size() && pushed[pushIndex] != popped[popIndex]){
                stk.push(pushed[pushIndex++]);
            }
            pushIndex++;
            popIndex++;

            while (!stk.empty() &&  stk.top() == popped[popIndex]){
                stk.pop();
                popIndex++;
            }
        }

        if (!stk.empty())
            return false;

        return true;
    }
};