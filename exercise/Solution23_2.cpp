#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct cmp{
    bool operator() (ListNode *node1, ListNode *node2){
        return node1->val > node2->val; //用于小顶堆
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for (auto &node: lists) {
            if (node){
                pq.push(node);
            }
        }

        ListNode *dummyHead = new ListNode();
        ListNode *cur = dummyHead;
        while (!pq.empty()){
            ListNode *node = pq.top();
            pq.pop();

            ListNode *next = node->next;
            //将节点连入结果
            cur->next = node;
            cur = cur->next;
            cur->next = nullptr;
            if (next)
                pq.push(next);
        }

        return dummyHead->next;
    }
};