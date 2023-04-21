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

void display(Node* head){
    if(head == NULL){
        return;
    }
    Node*temp = head;
    while (temp)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}

Node* mergeLL(Node*head1, Node* head2){
    Node* dummy = new Node(INT_MAX);
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* ptr3 = dummy;

    while(ptr1 && ptr2){
        if(ptr1->data <= ptr2->data){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }

    // while(ptr1){
    //     ptr3->next = ptr1;
    //     ptr1 = ptr1->next;
    //     ptr3 = ptr3->next;
    // }

    // while(ptr2){
    //     ptr3->next = ptr2;
    //     ptr2 = ptr2->next;
    //     ptr3 = ptr3->next;     
    // }

    //***** NOTE: Once one of the LL becomes NULL, it is sufficient to link ptr3 to the remaining bigger LL
    if(ptr1==NULL){
        ptr3->next = ptr2;
    }
    else{
        ptr3->next = ptr1;
    }

    return dummy->next;
}

int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    vector<int>v1 = {1, 5, 10, 30};
    vector<int>v2 = {1, 9, 40};

    for(int i=0; i<v1.size(); i++){
        insertAtTail(head1,v1[i]);
    }
    for(int i=0; i<v2.size(); i++){
        insertAtTail(head2,v2[i]);
    }

    Node* mergedHead = mergeLL(head1, head2);

    display(mergedHead);
}