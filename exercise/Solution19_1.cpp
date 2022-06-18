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
    MyListNode *removeNthFromEnd(MyListNode *head, int n) {
        MyListNode *dummyHead = new MyListNode(0, head);

        MyListNode *slow = dummyHead, *fast = dummyHead;
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        while (fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;
        return dummyHead->next;
    }
};