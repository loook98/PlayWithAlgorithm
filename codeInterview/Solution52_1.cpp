#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //遍历两边，利用set的方法，不是最好
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> set;
        ListNode *cur = headA;
        while (cur != nullptr){
            set.emplace(cur);
            cur = cur->next;
        }
        if (set.empty())
            return nullptr;

        cur = headB;
        while (cur != nullptr){
            if (set.count(cur))
                return cur;
            cur = cur->next;
        }
        return nullptr;
    }
};