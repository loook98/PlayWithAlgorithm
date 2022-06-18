#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *cur = head;
        unordered_set<ListNode*> set;
        while (cur != nullptr && !set.count(cur)){
            set.insert(cur);
            cur = cur->next;
        }
        return cur;
    }
};