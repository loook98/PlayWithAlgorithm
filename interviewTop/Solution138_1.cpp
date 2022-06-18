#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        unordered_map<Node *,Node *> map; // oldListNode --- newListNode

        Node *cur = head;
        //第一次遍历旧链表，构建旧节点与新节点的映射map
        while (cur != nullptr){
            Node *node = new Node(cur->val);
            map[cur] = node;

            cur = cur->next;
        }

        //第二次遍历旧链表，根据上边的map从而更新新链表中节点的next和random
        cur = head;
        while (cur != nullptr){
            Node *newListNode = map[cur];
            newListNode->next = map[cur->next];
            newListNode->random = map[cur->random];

            cur = cur->next;
        }

        return map[head];
    }
};