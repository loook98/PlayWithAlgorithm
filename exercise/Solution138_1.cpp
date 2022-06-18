#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
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
    Node *copyRandomList(Node *head) {
        unordered_map<Node *, Node *> old2new;

        Node *cur = head;
        //先生成新节点
        while (cur != nullptr){
            old2new[cur] = new Node(cur->val);
            cur = cur->next;
        }

        //再更新新节点的next和random
        cur= head;
        while (cur != nullptr){
            old2new[cur]->next = old2new[cur->next];
            old2new[cur]->random = old2new[cur->random];

            cur = cur->next;
        }

        return old2new[head];
    }
};