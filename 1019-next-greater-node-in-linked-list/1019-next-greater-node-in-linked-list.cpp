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
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        // if(head==NULL) return head;
        // if(head->next==NULL) return 0;
     
        vector<int> store;
        ListNode* temp=head;
        while(temp!=NULL){
            store.push_back(temp->val);
            temp=temp->next;
        }
        stack<int> st;
        int n=store.size();
           vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--){
           while(!st.empty() && st.top()<=store[i]){
            st.pop();
           }
           if(st.empty()) ans[i]=0;
           else ans[i]=st.top();
           st.push(store[i]);
        }
        return ans;
    }  
};