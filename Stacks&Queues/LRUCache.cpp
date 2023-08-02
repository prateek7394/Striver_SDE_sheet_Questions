// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key): Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value): Update the value of the key if the key exists. 
// Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, 
// evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

#include<bits/stdc++.h>
using namespace std;

// INTUTION:
// Here we use an unordered map and a doubly linked list
// In map, we store a node and its address
// Initially, we have a head node and a tail node.
// We insert each incoming new node just after the head node and store its address in the map.
// When the capacity becomes full, we delete a node that is lying just before the tail node(Least Recently Used(LRU))
// The nodes lie in the order from Most Recently used to Least Recently used from head to tail.
// Upon calling get() method, we again delete the existing node and insert it just after the head node and also
// update its address in the map.

class LRUCache {
public:
    class node {
        public:
        int key, val;
        node *next, *prev;
        node(int K, int V){
            key = K;
            val = V;
        }
    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    int cap;
    unordered_map<int, node*> m; 

// functions to add and delete a node
    void insertNode(node* newNode){
        node *temp = head->next;
        head->next = newNode;
        newNode->next = temp;
        newNode->prev = head;
        temp->prev = newNode;
    }

    void deleteNode(node* delNode){
        node *prev = delNode->prev;
        node *next = delNode->next;
        next->prev = prev;
        prev->next = next;
    }

// Functions to be implemented according to question
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.count(key)){
            node* existingNode = m[key];
            int ans = existingNode->val;
            m.erase(key);
            deleteNode(existingNode);
            insertNode(existingNode);
            m[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.count(key)){
            node *existingNode = m[key];
            m.erase(key);
            deleteNode(existingNode);
        }

        if(m.size()==cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        node *newNode = new node(key, value);
        insertNode(newNode);
        m[key] = head->next;
    }
};


int main()
{
    return 0;
}