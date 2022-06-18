#include <bits/stdc++.h>

using namespace std;

class MaxQueue {
private:
    queue<int> data;
    deque<int> maximum; //maximum中存可能成为队列最大值的元素
public:
    MaxQueue() {

    }

    int max_value() {
        if (maximum.empty())
            return -1;
        else{
            return maximum.front();
        }
    }

    void push_back(int value) {
        data.push(value);
        while (!maximum.empty() && value > maximum.back()){
            maximum.pop_back();
        }
        maximum.push_back(value);
    }

    int pop_front() {
        if (data.empty())
            return -1;
        int popV = data.front();
        data.pop();
        if (popV == maximum.front())
            maximum.pop_front();
        return popV;
    }
};
