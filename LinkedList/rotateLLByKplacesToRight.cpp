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

Node* rotateRight(Node* head, int k) {
        if(head==NULL){
            return head;
        }

        int len = 1;
        Node* tail = head;
        while(tail->next!=NULL){
            tail = tail->next;
            len++;
        }
        tail->next = head; // Link the last node to first node to make circular LL

        k = k%len;
        for(int i=0; i<len-k; i++){
            tail = tail->next; // move tail len-k times because upon rotating 1 time we move the tail 4 times in circular LL to get new pos of tail if len = 5
            //  i.e. len = pos + k;
        }

        Node *newHead = tail->next;
        tail->next = NULL;

        return newHead;
        
    }

int main()
{
    return 0;
}