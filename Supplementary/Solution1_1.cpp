#include <bits/stdc++.h>

using namespace std;

//补充题1 排序奇升偶降链表
//牛客： NC207 排序奇升偶降链表


struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *sortLinkedList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        //step1. 先把链表拆分成两个，一个奇数节点的，一个偶数节点的
        ListNode *oddDummyHead = new ListNode(0);
        ListNode *evenDummyHead = new ListNode(0);

        ListNode *preOdd = oddDummyHead, *preEven = evenDummyHead;
        ListNode *curOdd = head, *curEven = head->next;
        while (curEven != nullptr && curEven->next != nullptr) {
            preOdd->next = curOdd;
            preEven->next = curEven;

            preOdd = curOdd;
            preEven = curEven;

            curOdd = curEven->next;
            curEven = curEven->next->next;
        }
        if (curEven == nullptr) {
            preOdd->next = curOdd;

            preEven->next = nullptr;
        } else if (curEven->next == nullptr){
            preOdd->next = curOdd;
            curOdd->next = nullptr;

            preEven->next = curEven;
        }


        //step2. 翻转偶数链表
        evenDummyHead->next = reverse(evenDummyHead->next);

        //合并两个链表
        ListNode *res = new ListNode(0);
        ListNode *curRes = res;
        curOdd = oddDummyHead->next, curEven = evenDummyHead->next;
        while (curOdd != nullptr && curEven != nullptr) {
            if (curOdd->val <= curEven->val) {
                ListNode *next = curOdd->next;

                curRes->next = curOdd;
                curRes = curRes->next;
                curOdd->next = nullptr;

                curOdd = next;
            } else {
                ListNode *next = curEven->next;

                curRes->next = curEven;
                curRes = curRes->next;
                curEven->next = nullptr;

                curEven = next;
            }
        }
        if (curOdd != nullptr) {
            curRes->next = curOdd;
        }
        if (curEven != nullptr) {
            curRes->next = curEven;
        }

        //返回结果
        return res->next;
    }

    ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr, *cur = head, *next = nullptr;

        while (cur != nullptr) {
            next = cur->next;

            cur->next = prev;

            prev = cur;
            cur = next;
        }

        return prev;
    }
};