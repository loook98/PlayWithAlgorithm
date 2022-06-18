#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *cur = head;
        int cnt = 0;
        while (cur != nullptr && cnt < 2) {
            cnt++;
            cur = cur->next;
        }

        if (cnt < 2)
            return head;

        ListNode *newHead = reverse2Node(head);
        newHead->next->next = swapPairs(cur);
        return newHead;
    }

    ListNode *reverse2Node(ListNode *head){
        ListNode *nextNode = head->next;
        nextNode->next = head;
        head->next = nullptr;

        return nextNode;
    }
};