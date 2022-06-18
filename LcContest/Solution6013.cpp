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
    ListNode *mergeNodes(ListNode *head) {
        ListNode *cur = head;
        ListNode dummyRet(0);
        ListNode *retCur = &dummyRet;
        while (cur != nullptr) {
            if (cur->val == 0) {
                int sum = 0;
                cur = cur->next;
                while (cur != nullptr && cur->val != 0) {
                    sum += cur->val;
                    cur = cur->next;
                }
                if (sum != 0){
                    retCur->next = new ListNode(sum);
                    retCur = retCur->next;
                }
            }
        }
        return dummyRet.next;
    }
};