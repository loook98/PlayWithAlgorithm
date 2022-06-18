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
    ListNode *sortList(ListNode *head) {
        return mergeSort(head, nullptr);
    }

    //[left,right)进行归并排序
    ListNode *mergeSort(ListNode *left, ListNode *right) {
        if (left == nullptr)
            return nullptr;
        if (left->next == right){
            left->next = nullptr;
            return left;
        }

        //找到中点
        ListNode *slow = left, *fast = left;
        while (fast != right && fast->next != right) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *sortedLeft = mergeSort(left, slow);
        ListNode *sortedRight = mergeSort(slow, right);

        return merge(sortedLeft, sortedRight);
    }

    //传入[l1,null) 和[l2, null)。最后返回（dummyHead. null)
    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode *dummyHead = new ListNode(0, l1);
        ListNode *prev = dummyHead;

        ListNode *cur1 = l1, *cur2 = l2;
        while (cur1 != nullptr && cur2 != nullptr) {
            if (cur1->val <= cur2->val){
                prev->next = cur1;
                prev = cur1;
                cur1 = cur1->next;
            } else{
                prev->next = cur2;
                prev = cur2;
                cur2 = cur2->next;
            }
        }
        if (cur1 != nullptr){
            prev->next = cur1;
        }
        if (cur2 != nullptr){
            prev->next = cur2;
        }

        return dummyHead->next;
    }
};