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
    //翻转[a,b)区间的链表，返回翻转后的头节点
    ListNode *reverse(ListNode* a, ListNode *b){
        ListNode *pre = nullptr;
        ListNode *cur = a, *next = a;

        while (cur != b){
            next = cur->next;
            //翻转
            cur->next = pre;
            //移动指针
            pre = cur;
            cur = next;
        }
        return pre;
    }

    //k个一组翻转head为头的链表。返回返回后的头指针
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *a = head, *b = head;

        for (int i = 0; i < k; ++i) {
            //递归终止条件：链表中节点个数<k
            if (b == nullptr)
                return head;
            b = b->next;
        }

        ListNode *newHead = reverse(a, b);//翻转[a,b)区间链表
        a->next = reverseKGroup(b, k);
        return newHead;
    }
};