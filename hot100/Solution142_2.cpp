#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //双指针，看了题解
    //从链表头开始，slow每次走一步，fast走两步
    //当slow和fast相遇时，在链表定义一个ptr，和slow每次都走一步，最终连个节点会在入环点相遇
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head, *ptr = head;
        while (true){
            if (slow == nullptr || fast == nullptr || fast->next == nullptr)
                return nullptr;

            slow = slow->next;

            fast = fast->next->next;
            if (fast == slow)
                break;
        }

        while (ptr != slow){
            slow = slow->next;
            ptr = ptr->next;
        }
        return ptr;
    }
};