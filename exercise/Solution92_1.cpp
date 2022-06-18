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
    MyListNode *reverseBetween(MyListNode *head, int left, int right) {
        MyListNode *start = head;
        MyListNode *leftMin1 = nullptr;
        int cnt = 1;
        while (cnt < left) {
            if (cnt == left - 1)
                leftMin1 = start;
            start = start->next;
            cnt++;
        }

        //翻转
        MyListNode *prev = nullptr, *cur = start, *next = start;
        while (cnt <= right) {
            next = cur->next;

            cur->next = prev;

            prev = cur;
            cur = next;

            cnt++;
        }

        //拼接
        if (leftMin1 != nullptr)
            leftMin1->next = prev;
        start->next = cur;

        if (left == 1)
            return prev;
        else
            return head;
    }
};