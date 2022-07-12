#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA, *curB = headB;

        while (curA != curB){
            curA = curA->next;
            curB = curB->next;

            if (curA == nullptr && curB == nullptr)
                break;
            if (curA == nullptr)
                curA = headB;
            if (curB == nullptr)
                curB = headA;
        }

        return curA;
    }
};