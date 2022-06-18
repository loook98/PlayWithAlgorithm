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
    class FirstOfList {
    public:
        int val;
        ListNode *node;

        FirstOfList(int v, ListNode *n) : val(v), node(n){}

        bool operator < (const FirstOfList &other) const{
            return val > other.val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<FirstOfList> pq;
        for (auto &list: lists) {
            if (list)
                pq.push(FirstOfList(list->val, list));
        }

        ListNode *dummyHead = new ListNode();
        ListNode *cur = dummyHead;
        while (!pq.empty()){
            FirstOfList item = pq.top();
            pq.pop();

            cur->next = item.node;
            cur = cur->next;
            if (cur->next != nullptr)
                pq.push(FirstOfList(cur->next->val, cur->next));
            cur->next = nullptr;
        }

        return dummyHead->next;
    }
};