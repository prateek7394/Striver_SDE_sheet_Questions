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


void insertAtTail(Node* &head, int x){
    // Here head is taken by reference so as to modify the original LL
    Node *temp = new Node(x);
    if(head==NULL){
        head = temp;
        return;
    }
    Node *ptr = head;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
}

Node *getIntersectionNode(Node *headA, Node *headB) {
        Node *ptr1 = headA;
        Node *ptr2 = headB;

        while(ptr1!=NULL && ptr2!=NULL && ptr1!=ptr2){
            ptr1=ptr1->next;
            ptr2=ptr2->next;

            if(ptr1==ptr2) return ptr1;

            if(ptr1==NULL) ptr1 = headB;
            if(ptr2==NULL) ptr2 = headA;
        }

        return ptr1;
}
int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    vector<int>v1 = {4,1,8,4,5};
    vector<int>v2 = {5,6,1,8,4,5};

    for(int i=0; i<v1.size(); i++){
        insertAtTail(head1,v1[i]);
    }
    for(int i=0; i<v2.size(); i++){
        insertAtTail(head2,v2[i]);
    }

    Node* intersectingNode = getIntersectionNode(head1, head2);
    cout<<intersectingNode->data;
    return 0;
}