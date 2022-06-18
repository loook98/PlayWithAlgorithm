#include <bits/stdc++.h>

using namespace std;


struct MyListNode {
    int val;
    MyListNode *next;

    MyListNode() : val(0), next(nullptr) {}

    MyListNode(int x) : val(x), next(nullptr) {}

    MyListNode(int x, MyListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    MyListNode *deleteDuplicates(MyListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        MyListNode *dummyHead = new MyListNode(-101, head);

        MyListNode *prev = dummyHead, *cur = head;

        while (cur != nullptr){
            MyListNode* end = cur->next;
            if (end == nullptr){
                break;
            } else{
                while (end != nullptr && end->val == cur->val)
                    end = end->next;
                if (end != cur->next){
                    prev->next = end;
                    cur = end;
                } else{
                    prev = cur;
                    cur = end;
                }
            }
        }
        return dummyHead->next;
    }
};