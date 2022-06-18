#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> pq_left;//放左半部分元素的最大堆
    priority_queue<int, vector<int>, greater<int>> pq_right;//放右边元素的最小堆
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (pq_left.size() == pq_right.size()){
            pq_right.emplace(num);
            int temp = pq_right.top();
            pq_right.pop();

            pq_left.emplace(temp);
        } else{
            pq_left.emplace(num);
            int temp = pq_left.top();
            pq_left.pop();

            pq_right.emplace(temp);
        }
    }

    double findMedian() {
        if (pq_left.size() == pq_right.size()){
            return (pq_left.top() + pq_right.top())/2.0;
        } else if (pq_left.size() > pq_right.size()){
            return pq_left.top();
        } else {
            return pq_right.top();
        }
    }
};
