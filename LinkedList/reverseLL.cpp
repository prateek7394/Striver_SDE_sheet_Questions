#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;

    // Constructor
    Node(int x){
        data=x;
        next=NULL;
    }
};

// Iterative Approach:

Node* reverseList(Node* head) {
        if(head == NULL || head->next==NULL){
            return head;
        }
        Node* curr = head;
        Node* prev = NULL;
        Node* next;

        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }

// Recursive Approach:

Node* reverseList(Node* head) {

        if(head == NULL || head->next==NULL){
            return head;
        }
        Node* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
}

int main()
{
    return 0;
}