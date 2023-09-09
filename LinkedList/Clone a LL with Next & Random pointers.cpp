// PROBLEM: https://leetcode.com/problems/copy-list-with-random-pointer/description/?envType=daily-question&envId=2023-09-05
// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, 
// where each new node has its value set to the value of its corresponding original node. 
// Both the next and random pointer of the new nodes should point to new nodes in the copied list such that 
// the pointers in the original list and copied list represent the same list state. 
// None of the pointers in the new list should point to nodes in the original list.

// Return the head of the copied linked list.

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// ------------------ M1(Using map with key as original node and value as copied node)---------------

Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> mp; // {original node, copied node}
    Node* temp = head;

    while(temp){
        mp[temp] = new Node(temp->val);
        temp = temp->next;
    }

    temp = head;
    while(temp){
        // next of current copied node(mp[temp])is the map value(copied node)
        // corresponding to the next of original node(temp)
        mp[temp]->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];
        temp = temp->next;
    }

    return mp[head];
}
int main()
{
    return 0;
}