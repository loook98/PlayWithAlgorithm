#include <bits/stdc++.h>

using namespace std;


struct MyListNode {
    int val;
    MyListNode *next;

    MyListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    MyListNode *detectCycle(MyListNode *head) {
        MyListNode *slow = head, *fast =head;

        while (fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow){
                slow = head;
                while (fast != slow){
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }

        return nullptr;
    }
};