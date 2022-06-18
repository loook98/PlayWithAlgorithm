#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

//中序遍历二叉搜索树的结果就是有序的.
//所以采用中序遍历。用一个去全局的指针指向当前已链接好的链表的尾部，在每个节点处将链表尾部与这个节点相连，再更新全局指针即可，
class Solution {
public:
    Node *listLastNode = nullptr;

    Node *treeToDoublyList(Node *root) {
        if (root == nullptr)
            return nullptr;

        inOrder(root);
        //inOrder之后listLastNode指向链表最后一个节点
        //找到头结点，然后将链表连成循环链表
        Node *head = listLastNode;
        while (head->left != nullptr) {
            head = head->left;
        }

        head->left = listLastNode;
        listLastNode->right = head;
        return head;
    }

    void inOrder(Node *root) {
        if (root == nullptr)
            return;

        inOrder(root->left);

        //将已连接的链表尾部和当前节点连接起来
        if (listLastNode != nullptr)
            listLastNode->right = root;
        root->left = listLastNode;
        //更新已连接链表的尾部指针
        listLastNode = root;

        inOrder(root->right);
    }
};