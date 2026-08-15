/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode* reverseLL(ListNode* temp){
    ListNode* prev=NULL;
    while(temp!=NULL){
        ListNode* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}


ListNode* findknode(ListNode* temp , int k){
    k-=1;
    while(temp!=NULL && k>0){
      k--;
      temp=temp->next;
    }
    return temp;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1){
            return head;
        }
        ListNode* temp=head;
        ListNode* nextNode;
        ListNode* prevNode;
        while(temp!=NULL){
            ListNode* knode=findknode(temp,k);
            if(knode==NULL){
               if(prevNode) prevNode->next=temp;
                break;
            }else{
              nextNode=knode->next;
              knode->next=NULL;
              reverseLL(temp);
              if(temp==head){
                head=knode;
              }else{
                prevNode->next=knode;
              }
              prevNode=temp;
              temp=nextNode;
            }
        }
        return head;
    }
};