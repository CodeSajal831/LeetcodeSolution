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

ListNode* reverse(ListNode* head){
    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* front=head;
    while(curr!=NULL){
        front=curr->next;
        curr->next=prev;
        prev=curr;
        curr=front;
    }
    return prev;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead=reverse(slow->next);
        ListNode* first=head;
        ListNode* second=newHead;
        while(second!=NULL){
            if(first->val!=second->val){
                reverse(newHead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverse(newHead);
        return true;
    }
};