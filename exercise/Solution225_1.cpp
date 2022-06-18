#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q1, q2;
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        if (q1.empty() && q2.empty()){
            q1.emplace(x);
        } else if (!q1.empty()){
            q1.emplace(x);
        } else{
            q2.emplace(x);
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (!q1.empty()){
            while (true){
                int val = q1.front();
                q1.pop();
                if (q1.empty())
                    return val;
                q2.emplace(val);
            }
        } else{
            while (true){
                int val = q2.front();
                q2.pop();
                if (q2.empty())
                    return val;
                q1.emplace(val);
            }
        }
    }

    /** Get the top element. */
    int top() {
        if (!q1.empty()){
            while (true){
                int val = q1.front();
                q1.pop();
                if (q1.empty()){
                    q2.emplace(val);
                    return val;
                }
                q2.emplace(val);
            }
        } else{
            while (true){
                int val = q2.front();
                q2.pop();
                if (q2.empty()){
                    q1.emplace(val);
                    return val;
                }
                q1.emplace(val);
            }
        }
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }
};
