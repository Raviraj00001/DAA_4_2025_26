#include <iostream> 
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
Node* helper(Node* head){
Node* curr=head;
Node* last=nullptr;
   while(curr){
      Node* curnext=curr->next;
         if(curr->child!=NULL){
            Node* childHead=curr->child;
            Node* childtail=helper(curr->child);
            childHead->prev=curr;
            if(curr->next){
                childtail->next=curr->next;
                
                curr->next->prev = childtail; 
            }
            curr->next=childHead;
            curr->child = NULL;
            last=childtail;
         }else{
            last=curr;
         }
         curr=curnext;
   }
   return last;
}
    Node* flatten(Node* head) {
    if(head==NULL)return NULL;
    helper(head);
       return head;
    }
};