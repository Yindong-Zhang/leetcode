//
// Created by so_go on 2020/3/1.
//
/*
146. LRU缓存机制

        运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

进阶:

你是否可以在 O(1) 时间复杂度内完成这两种操作？

示例:

LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );

/*
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4

**/

#ifndef SRC_LRUCACHE_H
#define SRC_LRUCACHE_H
#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
struct Node{
    int key, val;
    Node *pre;
    Node *next;
};
class BiDirectionList{
public:
    Node head;
    Node *tail_ptr;
    BiDirectionList();
    void insertTail(int key, int val);
    void deleteNode(Node *ptr);
    ~BiDirectionList();

};

BiDirectionList::BiDirectionList():head{-1, -1, nullptr, nullptr} {
    tail_ptr = &head;
}

void BiDirectionList::insertTail(int key, int val){
    Node *nd = new Node{key, val, tail_ptr, nullptr};
    tail_ptr->next = nd;
    tail_ptr = nd;
}

void BiDirectionList::deleteNode(Node *ptr){
    if(ptr == nullptr){
        cout << "invalid pointer" << endl;
        return;
    }
    ptr->pre->next = ptr->next;
    // cout << &head << ' ' << ptr->pre << ' ' << ptr->next << endl;
    if(ptr->next != nullptr){
        ptr->next->pre = ptr->pre;
    }
    if(ptr == tail_ptr){
        tail_ptr= ptr->pre;
    }
    // cout << ptr << endl;
    delete ptr;
}
BiDirectionList::~BiDirectionList(){
    Node *ptr = head.next, *ptr_next;
    while(ptr != nullptr){
        ptr_next= ptr->next;
        delete ptr;
        ptr= ptr_next;
    }
}
/*
class LRUCache {
public:
    int cap, node_cnt;
    BiDirectionList _ls;
    unordered_map<int, Node*> _map;
    LRUCache(int capacity) {
        cap= capacity;
        node_cnt = 0;
    }

    int get(int key) {
        auto ptr = _map.find(key);
        if(ptr == _map.end()){
            return -1;
        }

        Node nd= *ptr->second;
        _ls.deleteNode(ptr->second);
        _ls.insertTail(nd.key, nd.val);
        _map[key]=_ls.tail_ptr;
        return nd.val;

    }

    void put(int key, int value) {
        if(_map.find(key) != _map.end()){
            // cout << "record already exist." << endl;
            Node *nd_ptr = _map.find(key)->second;
            _ls.deleteNode(nd_ptr);
            node_cnt--;
        }
        if(node_cnt == cap){
            Node nd_dl= *_ls.head.next;
            _ls.deleteNode(_ls.head.next);
            _map.erase(nd_dl.key);
            node_cnt--;
        }
        _ls.insertTail(key, value);
        _map[key] = _ls.tail_ptr;
        node_cnt++;
    }
};
*/

class LRUCache {
public:
    int cap;
    list<pair<int, int>> _ls;
    unordered_map<int, list<pair<int, int>>::iterator> _map;
    LRUCache(int capacity) {
        cap= capacity;
    }

    // 为了迭代器使用方便，将最近使用的数据放在链表头。
    int get(int key) {
        auto ptr = _map.find(key);
        if(ptr == _map.end()){
            return -1;
        }

        auto nd= *ptr->second;
        _ls.erase(ptr->second);
        _ls.push_front({nd.first, nd.second});
        _map[key]= _ls.begin();
        return nd.second;

    }

    void put(int key, int value) {
        if(_map.find(key) != _map.end()){
            // cout << "record already exist." << endl;
            auto itr = _map.find(key)->second;
            _ls.erase(itr);
        }
        if(_ls.size() == cap){
            auto pr= _ls.back();
            _ls.pop_back();
            _map.erase(pr.first);
        }
        _ls.push_front({key, value});
        _map[key] = _ls.begin();
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
#endif //SRC_LRUCACHE_H
