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
    void reorderList(MyListNode *head) {
        MyListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (slow == fast)
            return;

        //将右半部分的指针放入栈
        stack<MyListNode *> rightSubList;
        MyListNode *cur = slow;
        while (cur != nullptr) {
            rightSubList.push(cur);
            cur = cur->next;
        }

        //开始将节点插入空隙中
        cur = head;
        while (!rightSubList.empty()) {
            MyListNode *node = rightSubList.top();
            rightSubList.pop();

            MyListNode *next = cur->next;
            if (cur == node){
                cur->next = nullptr;
                return;
            }
            if (next == node){
                node->next = nullptr;
                return;
            }
            cur->next = node;
            node->next = next;

            cur = next;
        }
    }
};