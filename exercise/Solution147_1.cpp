#include <bits/stdc++.h>

using namespace std;

struct MyListNode {
    int val;
    MyListNode *next;

    MyListNode() : val(0), next(nullptr) {}

    MyListNode(int x) : val(x), next(nullptr) {}

    MyListNode(int x, MyListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    MyListNode *insertionSortList(MyListNode *head) {
        MyListNode *ordered = head; //已经排序号的部分的头结点
        while (ordered->next != nullptr)
            ordered = ordered->next;

        while (true){
            if (ordered == head)
                return head;

            //找到本轮待排序的节点
            MyListNode *cur = head;
            while (cur->next != ordered){
                cur = cur->next;
            }
            ordered = cur;
            //插入
            int curVal = cur->val;
            while (cur->next != nullptr && cur->next->val < curVal){
                cur->val = cur->next->val;
                cur = cur->next;
            }
            cur->val = curVal;
        }

    }
};