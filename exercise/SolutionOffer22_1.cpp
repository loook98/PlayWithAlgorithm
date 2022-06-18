#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getKthFromEnd(ListNode *head, int k) {
        ListNode *slow = head, *fast = head;

        for (int i = 0; i < k - 1; ++i) {
            fast = fast->next;
            if (fast == nullptr)
                return head;
        }

        while (fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};