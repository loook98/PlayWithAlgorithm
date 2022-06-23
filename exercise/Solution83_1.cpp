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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr)
            return head;

        ListNode *slow = head, *fast = head->next;

        while (fast != nullptr){
            while (fast != nullptr && fast->val == slow->val){
                fast = fast->next;
            }

            slow->next = fast;
            if (fast != nullptr){
                slow = fast;
                fast = fast->next;
            }
        }

        return head;
    }
};