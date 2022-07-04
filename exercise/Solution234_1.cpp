#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//回文链表，O(1)空间复杂度
class Solution {
public:
    bool isPalindrome(ListNode *head) {
        ListNode *fast = head, *slow = head;
        ListNode *tail = head; //slow的前一个元素

        //快慢指针，将链表分为两部分
        while (fast != nullptr && fast->next != nullptr){
            tail = slow;

            slow = slow->next;
            fast = fast->next->next;
        }
        tail->next = nullptr; //将前半部分断开
        if (fast != nullptr && slow != head) //奇数情况，slow后移一位
            slow = slow->next;

        //翻转前半部分
        ListNode *prev = nullptr, *cur = head, *next = nullptr;
        while (cur != nullptr){
            next = cur->next;

            //翻转
            cur->next = prev;
            //后移指针
            prev = cur;
            cur = next;
        }
        //翻转后prev为新头节点
        //比较是否是回文
        ListNode *it = prev;
        while (it != nullptr){
            if (it->val != slow->val)
                return false;

            it = it->next;
            slow = slow->next;
        }

        return true;
    }
};