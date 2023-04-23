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

bool isPalindrome(Node* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        Node* slow = head, *fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* curr = slow;
        Node* prev = NULL;
        Node* next;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        fast = head;

        while(prev){
            if(prev->data!=fast->data){
                return false;
            }
            prev = prev->next;
            fast = fast->next;
        }

        return true;
    }

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

int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    vector<int>v1 = {4,1,8,1,4};
    vector<int>v2 = {5,6,1,8,4,5};

    for(int i=0; i<v1.size(); i++){
        insertAtTail(head1,v1[i]);
    }
    for(int i=0; i<v2.size(); i++){
        insertAtTail(head2,v2[i]);
    }
    cout<<isPalindrome(head1)<<endl;
    cout<<isPalindrome(head2);
    return 0;
}