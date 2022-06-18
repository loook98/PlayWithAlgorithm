
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    //看了题解
    Node *copyRandomList(Node *head) {
        /*//复制正常链表
        Node *cur = head;
        Node *dummyHead = new Node(0), *pre = dummyHead;

        while (cur != nullptr){
            Node *node = new Node(cur->val);
            pre->next = node;
            pre = node;
            cur = cur->next;
        }
        return dummyHead->next;*/

        if (head == nullptr)
            return nullptr;

        Node *cur = head;
        unordered_map<Node*, Node*> map;

        //建立旧链表节点与新链表节点的映射关系
        while (cur != nullptr){
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }

        //修改新链表节点的next和random指针
        cur = head;
        while (cur != nullptr){
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }

        return map[head];
    }
};
