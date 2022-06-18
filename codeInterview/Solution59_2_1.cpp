#include <bits/stdc++.h>

using namespace std;

//error
class MaxQueue {
public:
    queue<int> queue;//用于记录所有元素的队列
    deque<int> deque;// 用于保存当前最大值的双向队列，back是最大元素，front
    MaxQueue() {

    }

    int max_value() {
        if (queue.empty())
            return -1;

        return deque.back();
    }

    void push_back(int value) {
        queue.push(value);
        if (deque.empty() || value >= deque.back())
            deque.push_back(value);
    }

    int pop_front() {
        if (queue.empty())
            return -1;
        int popVal = queue.front();
        queue.pop();
        if (deque.front() == popVal)
            deque.pop_front();
        return popVal;
    }
};