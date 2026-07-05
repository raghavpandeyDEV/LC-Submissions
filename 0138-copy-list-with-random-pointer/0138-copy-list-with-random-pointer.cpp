/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // adding copy nodes btw org list
        Node*temp=head;
        while(temp){
            Node*copyNode=new Node(temp->val);
            copyNode->next=temp->next;
            temp->next=copyNode;
            temp=temp->next->next;
        }
        // making copies point to its random copy
        temp=head;
        while(temp && temp->next){
            Node*copyNode=temp->next;
            if(temp->random)copyNode->random=temp->random->next;
            temp=temp->next->next;
        }

        //making copies point to next copy
        Node*dummy=new Node(-1);
        Node*res=dummy;

        temp=head;
        while(temp){
       res->next=temp->next;
       temp->next=temp->next->next;
       temp=temp->next;
       res=res->next;
        }
        return dummy->next;
    }
};