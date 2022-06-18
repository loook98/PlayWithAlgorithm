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
    MyListNode *mergeTwoLists(MyListNode *list1, MyListNode *list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        MyListNode *head = nullptr, *cur1 = list1, *cur2 = list2;
        if (list1->val < list2->val){
            head = cur1;
            cur1 = cur1->next;
            head->next = nullptr;
        } else{
            head = cur2;
            cur2 = cur2->next;
            head->next = nullptr;
        }
        MyListNode *cur = head;
        while (cur1 != nullptr && cur2 != nullptr){
            if (cur1->val < cur2->val){
                cur->next = cur1;
                cur1 = cur1->next;

                cur = cur->next;
                cur->next = nullptr;
            } else{
                cur->next = cur2;
                cur2 = cur2->next;

                cur = cur->next;
                cur->next = nullptr;
            }
        }

        while (cur1 != nullptr){
            cur->next = cur1;
            cur1 = cur1->next;

            cur = cur->next;
            cur->next = nullptr;
        }
        while (cur2 != nullptr){
            cur->next = cur2;
            cur2 = cur2->next;

            cur = cur->next;
            cur->next = nullptr;
        }

        return head;
    }
};