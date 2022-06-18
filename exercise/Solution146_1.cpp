#include <bits/stdc++.h>

using namespace std;

class MyListNode{
public:
    int m_key;
    int m_value;
    MyListNode *prev = nullptr, *next = nullptr;
public:
    MyListNode(int key, int value) : m_key(key), m_value(value){

    }
};

class LRUCache {
public:
    int m_capacity;
    int m_size;
    MyListNode *dummyHead, *tail;
    unordered_map<int, MyListNode *> m_map;

    LRUCache(int capacity): m_capacity(capacity) {
        m_size = 0;
        dummyHead = new MyListNode(-1, -1);
        tail = nullptr;
    }

    int get(int key) {
        if (!m_map.empty() && m_map.count(key)){
            int ret = m_map[key]->m_value;
            moveToTail(m_map[key]);
            return ret;
        } else{
            return -1;
        }
    }

    void put(int key, int value) {
        if (!m_map.empty() && m_map.count(key)){ //已经有，更新值即可
            m_map[key]->m_value = value;
            moveToTail(m_map[key]);
        } else{   //
            if (m_size < m_capacity){ //不需替换，直接加到尾部
                MyListNode *newNode = new MyListNode(key, value);
                m_map[key] = newNode;
                if (tail == nullptr){//链表为空
                    dummyHead->next = newNode;
                    newNode->prev = dummyHead;
                    tail = newNode;
                } else{
                    tail->next = newNode;
                    newNode->prev = tail;
                    tail = newNode;
                }
                m_size++;
            } else{ //将链表头的key,value更新(淘汰一个)，移到尾部
                MyListNode *head = dummyHead->next;
                m_map.erase(head->m_key);

                head->m_key = key;
                head->m_value = value;
                m_map[key] = head;
                moveToTail(head);
            }
        }
    }

    //将node节点移到链表尾部
    void moveToTail(MyListNode *node){
        //如果node就是尾节点，没有必要移动
        if (node == tail)
            return;

        MyListNode *nodePrev = node->prev;
        MyListNode *nodeNext = node->next;

        //先移除这个节点
        nodePrev->next = nodeNext;
        nodeNext->prev = nodePrev;
        //再移到尾部
        tail->next = node;
        node->prev = tail;
        //更新tail
        tail = node;
    }
};