#include<bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
   ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
 ListNode(int x, ListNode *next) : val(x), next(next) {}
};

 ListNode* doubleIt(ListNode* head) {
        string str = "";
        ListNode* temp = head;
        while(temp!=NULL){
            string s1 = to_string(temp->val);
            str+= s1;
            temp = temp->next;
        }

        int d = stoi(str);
        cout<<d<<endl;
        d = d*2;
        string s = to_string(d);
        
        ListNode *node = new ListNode(int(s[0]));
        ListNode* ans = node;
        
        for(int i=1; i<s.size(); i++){
            ListNode *newNode = new ListNode(int(s[i]));
            node->next = newNode;
            node = newNode;
        }
        
        return ans;
    }

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(8);
    head->next->next = new ListNode(9);

    ListNode* ans = doubleIt(head);
    
    return 0;
}