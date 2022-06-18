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
        MyListNode *cur = head->next; //当前准备插入前边的元素

        while (cur != nullptr) {
            int curVal = cur->val;
            //找到前边第一个大于curVal的节点
            MyListNode *node = head;
            while (node != cur && node->val < curVal)
                node = node->next;
            //插入
            int preVal = curVal;
            while (node != cur){
                int nodeVal = node->val;
                node->val = preVal;
                preVal = nodeVal;

                node = node->next;
            }
            node->val = preVal;

            //准备插入下一个节点
            cur = cur->next;
        }

        return head;
    }
};