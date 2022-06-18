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
    //翻转[start,end)区间内的链表
    MyListNode *reverse(MyListNode *start, MyListNode *end){
        MyListNode *pre = nullptr, *cur = start, *next = start;
        while (cur != end){
            next = cur->next;

            cur->next = pre;

            pre = cur;
            cur = next;
        }

        return pre;
    }

    MyListNode *reverseKGroup(MyListNode *head, int k) {
        if (head == nullptr)
            return nullptr;
        //找到K个一组的范围
        MyListNode *cur = head;
        for (int i = 0; i < k; ++i) {
            if (cur == nullptr)
                return head;

            cur = cur->next;
        }
        MyListNode *newHead = reverse(head, cur);

        MyListNode *nextHead = reverseKGroup(cur, k);
        head->next = nextHead;

        return newHead;
    }
};