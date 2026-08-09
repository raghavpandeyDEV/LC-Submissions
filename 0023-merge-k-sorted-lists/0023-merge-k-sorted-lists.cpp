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
      priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq; 
       // {node->val , node}
 
       for(int i=0;i<lists.size();i++){
      if(lists[i]!=NULL)pq.push({lists[i]->val,lists[i]});
       }
       
       ListNode*dummy=new ListNode(-1);
       ListNode*temp=dummy;

       while(!pq.empty()){
        ListNode*node=pq.top().second;
        pq.pop();
        if(node->next)pq.push({node->next->val,node->next});
        temp->next=new ListNode(node->val);
        temp=temp->next;
       }

       return dummy->next;
    }
};