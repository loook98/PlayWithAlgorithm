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
    vector<int> nodesBetweenCriticalPoints(ListNode *head) {
        vector<int> res(2, -1);
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr ||
            head->next->next->next == nullptr)
            return res;

        vector<int> extremePoint;
        ListNode *cur = head->next, *pre =head;
        int index = 1;
        while (cur->next != nullptr) {
            if ((cur->val < pre->val && cur->val < cur->next->val) || (cur->val > pre->val && cur->val > cur->next->val))
                extremePoint.push_back(index);

            pre = cur;
            cur = cur->next;
            index++;
        }

        if (extremePoint.size() < 2)
            return res;
        //maxDistance
        res[1] = extremePoint[extremePoint.size()-1] - extremePoint[0];
        //minDistance
        int min = 100000, temp;
        for (int i = 1; i < extremePoint.size(); ++i) {
            temp = extremePoint[i] - extremePoint[i-1];
            if (temp < min)
                min = temp;
        }
        res[0] = min;

        return res;
    }
};