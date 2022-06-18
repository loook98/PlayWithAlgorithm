#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//递归归并排序
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        return mergeSort(head, nullptr);
    }

    ListNode *mergeSort(ListNode *head, ListNode *tail) { // [head,tail)
        if (head == nullptr)
            return nullptr;
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }

        ListNode *slow = head, *fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail)
                fast = fast->next;
        }

        ListNode *mid = slow;
        return merge(mergeSort(head, slow), mergeSort(slow, tail));
    }

    ListNode *merge(ListNode *head1, ListNode *head2) {
        auto *dummyHead = new ListNode(0);
        ListNode *cur = dummyHead;
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val < head2->val) {
                cur->next = head1;
                head1 = head1->next;
            } else {
                cur->next = head2;
                head2 = head2->next;
            }
            cur = cur->next;
        }
        if (head1 != nullptr)
            cur->next = head1;
        if (head2 != nullptr)
            cur->next = head2;
        return dummyHead->next;
    }
};