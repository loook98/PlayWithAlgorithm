#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //快慢指针
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return false;
        ListNode *slow = head, *fast = head;
        slow = head->next;
        fast = head->next->next;
        while (slow != fast){
            if (fast == nullptr || fast->next == nullptr)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};