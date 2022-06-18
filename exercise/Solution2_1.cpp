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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *cur1 = l1, *cur2 = l2;

        ListNode *dummyHead = new ListNode();
        ListNode *prev = dummyHead;

        int carryNum = 0;
        while (cur1 != nullptr && cur2 != nullptr){
            int temp = cur1->val + cur2->val + carryNum;

            ListNode *node = new ListNode(temp % 10);
            carryNum = temp / 10;
            prev->next = node;
            prev = node;

            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        while (cur1 != nullptr){
            int temp = cur1->val + carryNum;

            ListNode *node = new ListNode(temp % 10);
            carryNum = temp / 10;
            prev->next = node;
            prev = node;

            cur1 = cur1->next;
        }
        while (cur2 != nullptr){
            int temp = cur2->val + carryNum;

            ListNode *node = new ListNode(temp % 10);
            carryNum = temp / 10;
            prev->next = node;
            prev = node;

            cur2 = cur2->next;
        }
        //处理最后的进位
        if (carryNum != 0){
            ListNode *node = new ListNode(carryNum);

            prev->next = node;
            prev = node;
        }

        return dummyHead->next;
    }
};