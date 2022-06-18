#include <bits/stdc++.h>

using namespace std;

class MinStack {
public:
    stack<int> valueStk, minStk;
    MinStack() {

    }

    void push(int val) {
        valueStk.push(val);
        if (minStk.empty() || val <= minStk.top()){
            minStk.push(val);
        }
    }

    void pop() {
        int v = valueStk.top();
        valueStk.pop();

        if (v == minStk.top()){
            minStk.pop();
        }
    }

    int top() {
        return valueStk.top();
    }

    int getMin() {
        return minStk.top();
    }
};
