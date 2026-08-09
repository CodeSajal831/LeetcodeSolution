class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* fast=head;
       ListNode* slow=head;
       if(head==NULL || head->next==NULL) return NULL;
     
       for(int i=1;i<=n;i++){
        fast=fast->next;
       }
        if(fast==NULL) return head->next;
       while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
       }
      
        ListNode* temp=slow->next;
       slow->next=slow->next->next;
       delete(temp);
       return head;

    }
};