#include <bits/stdc++.h>
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
    
Node *detectCycle(Node *head) {

        if(head==NULL || head->next==NULL){
            return NULL;
        }
        Node *slow = head, *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                slow = head;
            
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return NULL;
    }
int main()
{
    return 0;
}