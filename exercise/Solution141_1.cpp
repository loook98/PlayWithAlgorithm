#include <bits/stdc++.h>

using namespace std;


struct MyListNode {
    int val;
    MyListNode *next;

    MyListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(MyListNode *head) {
        MyListNode *slow = head, *fast = head;

        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }
};