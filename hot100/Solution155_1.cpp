#include <bits/stdc++.h>

using namespace std;

class MinStack {
public:
    stack<int> valStack;
    stack<int> minStack;
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int val) {
        valStack.push(val);
        if (minStack.empty() || val <= minStack.top())
            minStack.push(val);
    }

    void pop() {
        int top = valStack.top();
        valStack.pop();
        if (top == minStack.top())
            minStack.pop();
    }

    int top() {
        return valStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};