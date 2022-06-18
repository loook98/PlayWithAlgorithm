#include <bits/stdc++.h>

using namespace std;

class MedianFinder {
public:
    priority_queue<int , vector<int>, less<int>> leftMaxHeap; //左边的最大堆
    priority_queue<int, vector<int>, greater<int>> rightMinHeap; //右边的最大堆
    int index = 1; //当前插入的元素是数据流的第几个元素

    //要保证：
    //1.两个堆中的元素个数在某一时刻最多相差1。
    // 实现：在第奇数个数据时将其插入左边堆，第偶数个数据时将其插入右边的堆。
    //2.左边堆中的元素都要小于右边堆中的元素。
    // 实现：左边的堆插入元素时，先插入，然后将最大的取出插入右边。
    //      右边的堆插入元素时，先插入，然后将最小的元素取出插入右边。

    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if ((index & 1) == 1){
            //奇数时先插入左边的堆
            leftMaxHeap.push(num);

            //保证左边堆中的元素均小于右边堆中的元素
            int tmp = leftMaxHeap.top();
            leftMaxHeap.pop();
            rightMinHeap.push(tmp);
        } else{
            //偶数时先插入右边的堆
            rightMinHeap.push(num);

            //保证左边堆中的元素均小于右边堆中的元素
            int tmp = rightMinHeap.top();
            rightMinHeap.pop();
            leftMaxHeap.push(tmp);
        }
        index++;
    }

    double findMedian() {
        if (leftMaxHeap.size() == rightMinHeap.size()){
            return (double)(leftMaxHeap.top() + rightMinHeap.top()) / 2;
        } else{
            if (leftMaxHeap.size() > rightMinHeap.size()){
                return leftMaxHeap.top();
            }else{
                return rightMinHeap.top();
            }
        }
    }
};