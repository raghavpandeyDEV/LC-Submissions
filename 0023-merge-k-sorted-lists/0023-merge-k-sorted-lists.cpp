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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>temp;
        for(int i=0;i<lists.size();i++){
            ListNode*head=lists[i];
            while(head!=NULL){
                temp.push_back(head->val);
                head=head->next;
            }
        }
        sort(temp.begin(),temp.end());
        ListNode*dummy=new ListNode(-1);
        ListNode*curr=dummy;
        for(int i=0;i<temp.size();i++){
            curr->next=new ListNode(temp[i]);
            curr=curr->next;
        }
        return dummy->next;
        
    }
};