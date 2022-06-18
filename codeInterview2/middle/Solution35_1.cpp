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
    Node *copyRandomList(Node *head) {
        createNewNode(head);
        updateRandom(head);
        return getNewList(head);
    }

    //step1:对每个节点，生成一个N'节点，val赋为源节点的值，并把这个新节点连到源节点后
    void createNewNode(Node *head) {
        Node *cur = head;

        while (cur != nullptr) {
            Node *newNode = new Node(cur->val);

            newNode->next = cur->next;
            cur->next = newNode;

            cur = newNode->next;
        }
    }

    //step2:更新每个新节点random指针
    void updateRandom(Node *head) {
        Node *cur = head;

        while (cur != nullptr) {
            Node *newNode = cur->next;
            if (cur->random != nullptr)
                newNode->random = cur->random->next;

            cur = newNode->next;
        }
    }

    //step3:从长链表中拆分处新链表
    Node *getNewList(Node *head) {
        Node *curOldList = head;  //用来遍历旧链表
        Node *curNewList = nullptr; //用来遍历新链表
        Node *newList = nullptr;

        if (curOldList != nullptr) {
            newList = curNewList = curOldList->next;
        }

        while (curOldList != nullptr) {
            curOldList->next = curNewList->next;
            curOldList = curOldList->next;
            if (curOldList != nullptr)
                curNewList->next = curOldList->next;
            curNewList = curNewList->next;
        }

        return newList;
    }
};