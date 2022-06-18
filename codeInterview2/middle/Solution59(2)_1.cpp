#include <bits/stdc++.h>

using namespace std;


class MaxQueue {
private:
    queue<int> data;
    deque<int> descendQueue; //单调队列，从队头单调递减
public:
    MaxQueue() {

    }

    int max_value() {
        if (descendQueue.empty())
            return -1;

        return descendQueue.front();
    }

    void push_back(int value) {
        data.push(value);

        while (!descendQueue.empty() && descendQueue.back() < value){
            descendQueue.pop_back();
        }
        descendQueue.push_back(value);
    }

    int pop_front() {
        if (data.empty())
            return -1;

        int popNum = data.front();
        data.pop();
        if (descendQueue.front() == popNum)
            descendQueue.pop_front();

        return popNum;
    }
};