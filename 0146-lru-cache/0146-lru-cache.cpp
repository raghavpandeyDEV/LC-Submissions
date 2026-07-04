class LRUCache {
     class ListNode {
    public:
        int key, val;
        ListNode *prev, *next;

        ListNode(int k, int v) {
            key = k;
            val = v;
            prev = next = nullptr;
        }
    };

    unordered_map<int,ListNode*>mpp;  // { key , address}
    int capacity;
    ListNode*head;
    ListNode*tail;
public: 
   void deleteNode(ListNode*root){
    ListNode*prevNode=root->prev;
    ListNode*nextNode=root->next;
    prevNode->next=nextNode;
    nextNode->prev=prevNode;
   }

   void insertAfterHead(ListNode*root){
    ListNode*currAfterHead=head->next;
    head->next=root;
    root->next=currAfterHead;
    root->prev=head;
    currAfterHead->prev=root;
   }


    LRUCache(int capacity) {
       this->capacity = capacity;

        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end())return -1;
        ListNode*node=mpp[key];
        deleteNode(node);
        insertAfterHead(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            ListNode*node=mpp[key];
            node->val=value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else{
            if(mpp.size()==capacity){
                ListNode*node=tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }
            ListNode*node = new ListNode(key,value);
            mpp[key]=node;
            insertAfterHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */