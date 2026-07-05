/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {

public:
    void dfs(Node*curr , Node*clone_node,unordered_map<Node*,Node*>&mpp){
    for(auto it : curr->neighbors){
            if(mpp.find(it)==mpp.end()){
                Node*clone=new Node(it->val);
                mpp[it]=clone;
                clone_node->neighbors.push_back(clone);
                dfs(it,clone,mpp);
            }
            else{
                clone_node->neighbors.push_back(mpp[it]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>mpp;
        if(!node)return NULL;

        Node*clone_node=new Node(node->val);
        mpp[node]=clone_node;
        dfs(node,clone_node,mpp);
        return clone_node;
        
    }
};