#include <bits/stdc++.h>

using namespace std;

struct MyListNode {
    int val;
    MyListNode *next;

    MyListNode(int x) : val(x), next(NULL) {}
};

//环形链表2
class Solution {
public:
    MyListNode *detectCycle(MyListNode *head) {
        MyListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow){
                slow = head;
                while (slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return nullptr;
    }
};