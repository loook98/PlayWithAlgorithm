#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//递归反转链表
class Solution {
public:
    //返回值：反转后的链表头结点
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        //last记录后边的链表翻转后的尾节点.也是未翻转前后边部分的头节点。
        ListNode *last = head->next;
        head->next = nullptr;
        ListNode *newHead = reverseList(last);
        last->next = head;
        return newHead;
    }
};