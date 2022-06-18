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
    MyListNode *reverseList(MyListNode *head) {
        MyListNode *pre = nullptr, *cur = head, *next = head;

        while (cur != nullptr){
            next = cur->next;

            cur->next = pre;

            pre = cur;
            cur = next;
        }

        return pre;
    }
};