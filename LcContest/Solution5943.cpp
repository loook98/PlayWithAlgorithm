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
    ListNode *deleteMiddle(ListNode *head) {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *prev = dummyHead, *fast = head, *slow = head;

        while (true){
            if (fast == nullptr || fast->next == nullptr)
                break;
            prev = prev->next;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        return dummyHead->next;
    }
};