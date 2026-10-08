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
    ListNode* reverse(ListNode* head) {
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*forward=NULL;

        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
     /*   find middle of LL
       reverese frm middle to end
       start iterating using 2 ptrs -> start and mid simul 
       */

       ListNode*slow=head;
       ListNode*fast=head;

       while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
       }
       ListNode*mid=reverse(slow);
       slow=head;

       

       while(slow && mid){
        if(slow->val!=mid->val)return false;
        slow=slow->next;
        mid=mid->next;
       }
return true;

    }
};