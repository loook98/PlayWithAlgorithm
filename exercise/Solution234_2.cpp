#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//先用快慢指针找到链表中点，然后翻转前半部分，进行比较即可。
class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        //1. 先找到链表中点
        ListNode *slow = head, *fast = head;
        ListNode *beforeSlow = head; //slow之前的节点
        while (fast != nullptr && fast->next != nullptr){
            beforeSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //此时slow为后半部分的头结点
        beforeSlow->next = nullptr;
        if (fast != nullptr) //节点个数为奇数的话，slow后移一位
            slow = slow->next;

        //2. 翻转前半部分
        ListNode *prev = nullptr, *cur = head, *next = head;
        while (cur != nullptr){
            next = cur->next;

            cur->next = prev;

            prev = cur;
            cur = next;
        }
        //此时prev为前半部分翻转后的头结点

        //3.比较两部分
        while (prev != nullptr && slow != nullptr){
            if (prev->val != slow->val)
                return false;

            prev = prev->next;
            slow = slow->next;
        }

        return true;
    }
};