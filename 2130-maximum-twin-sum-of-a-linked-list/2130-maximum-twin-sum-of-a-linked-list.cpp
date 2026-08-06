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
    ListNode*reverse(ListNode*head){
       ListNode*curr=head;
       ListNode*prev=NULL;
       ListNode*forward=NULL;

       while(curr){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
       }
       return prev;
    }
public:
    int pairSum(ListNode* head) {
        // finding middle of list
        ListNode*slow=head;
        ListNode*fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*revHead=reverse(slow);
        ListNode*curr=head;
        
        int maxi=INT_MIN;

        while(revHead && curr){
            maxi=max(maxi , revHead->val+curr->val );
            revHead=revHead->next;
            curr=curr->next;
        }
        return maxi;
    }
};