#include <bits/stdc++.h>

using namespace std;

struct DLinkedNode {
    int key, value;
    DLinkedNode *pre;
    DLinkedNode *next;

    DLinkedNode() : key(0), value(0), pre(nullptr), next(nullptr) {}

    DLinkedNode(int k, int v) : key(k), value(v), pre(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    int size = 0, capacity;
    unordered_map<int, DLinkedNode *> map;
    DLinkedNode *head, *tail; //链表尾为最近最久为使用的元素


    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        if (!map.count(key))
            return -1;
        DLinkedNode *node = map[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (map.count(key)) {
            DLinkedNode *existedNode = map[key];
            existedNode->value = value;
            moveToHead(existedNode);
        } else{
            if (size < capacity) {
                DLinkedNode *node = new DLinkedNode(key, value);
                map.insert(make_pair(key, node));
                addToHead(node);
                size++;
            } else { //容量已满
                DLinkedNode *removedNode = removeTail();
                map.erase(removedNode->key);
                delete removedNode; //防止内存泄漏
                DLinkedNode *node = new DLinkedNode(key, value);
                map.insert(make_pair(key, node));
                addToHead(node);
            }
        }
    }

    void addToHead(DLinkedNode *node) {
        node->pre = head;
        node->next = head->next;

        node->next->pre = node;
        head->next = node;
    }

    void removeNode(DLinkedNode *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void moveToHead(DLinkedNode *node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode *removeTail() {
        DLinkedNode *node = tail->pre;
        removeNode(node);
        return node;
    }
};