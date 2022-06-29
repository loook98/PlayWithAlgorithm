#include <bits/stdc++.h>

using namespace std;

class MedianFinder {
public:
    priority_queue<int> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;
    int steps = 1;

    MedianFinder() {

    }

    void addNum(int num) {
        if (steps % 2 != 0){
            leftMaxHeap.push(num);

            //为了保证右边的堆中元素均大于左边堆中元素，
            //上边左边插入后，取出最大插入右边
            int maxOfLeft = leftMaxHeap.top();
            leftMaxHeap.pop();
            rightMinHeap.push(maxOfLeft);
        } else{
            rightMinHeap.push(num);

            //为了保证左边堆中元素均小于右边堆中元素
            //上边右边插入后，取出最小的插入左边
            int minOfRight = rightMinHeap.top();
            rightMinHeap.pop();
            leftMaxHeap.push(minOfRight);
        }
        steps++;
    }

    double findMedian() {
        if (leftMaxHeap.empty() && rightMinHeap.empty())
            return 0.0;

        if (leftMaxHeap.size() > rightMinHeap.size())
            return leftMaxHeap.top();
        else if (rightMinHeap.size() > leftMaxHeap.size())
            return rightMinHeap.top();
        else
            return (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */