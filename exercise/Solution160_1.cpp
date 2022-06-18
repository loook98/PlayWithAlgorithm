#include <bits/stdc++.h>

using namespace std;


struct MyListNode {
    int val;
    MyListNode *next;

    MyListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    MyListNode *getIntersectionNode(MyListNode *headA, MyListNode *headB) {
        MyListNode *curA = headA, *curB = headB;

        while (curA != curB){
            if (curA == nullptr)
                curA = headB;
            else
                curA = curA->next;

            if (curB == nullptr)
                curB = headA;
            else
                curB = curB->next;
        }

        return curA;
    }
};