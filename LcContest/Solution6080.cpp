#include <bits/stdc++.h>

using namespace std;

//6080. 使数组按非递减顺序排列

class MyListNode{
public:
    int val;
    MyListNode *prev;
    MyListNode *next;
    MyListNode(int v): val(v){
        prev = nullptr;
        next = nullptr;
    }
};


//**错误解法**,一次要删当前数组中所有i<i-1的i，不是迭代地删
class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n =  nums.size();
        if (n == 1)
            return 0;

        MyListNode *head = new MyListNode(nums[0]);
        MyListNode *prev = head;
        for (int i = 1; i < n; ++i) {
            MyListNode *cur = new MyListNode(nums[i]);
            prev->next = cur;
            cur->prev = prev;

            prev = cur;
        }

        int res = 0;
        prev = head;
        MyListNode *cur = head->next;
        while (cur != nullptr){
            if (cur->val < prev->val){
                cout << "delete " << cur->val << endl;
                MyListNode *next = cur->next;
                //delete cur;
                prev->next = next;
                next->prev = prev;

                cur = next;
                res ++;
            } else{
                prev = cur;
                cur = cur->next;
            }
        }

        return res;
    }
};