#include <bits/stdc++.h>

using namespace std;

class MyQueue {
public:
    stack<int> pushStack;
    stack<int> popStack;

    MyQueue() {

    }

    void push(int x) {
        //先把popStack中的元素全搬过来
        while (!popStack.empty()){
            int v = popStack.top();
            popStack.pop();

            pushStack.push(v);
        }
        //再push
        pushStack.push(x);
    }

    int pop() {
        //先把pushStack中的元素全搬过来
        while (!pushStack.empty()){
            int v = pushStack.top();
            pushStack.pop();

            popStack.push(v);
        }
        //再pop
        int ret = popStack.top();
        popStack.pop();
        return ret;
    }

    int peek() {
        //先把pushStack中的元素全搬过来
        while (!pushStack.empty()){
            int v = pushStack.top();
            pushStack.pop();

            popStack.push(v);
        }

        return popStack.top();
    }

    bool empty() {
        return pushStack.empty() && popStack.empty();
    }
};