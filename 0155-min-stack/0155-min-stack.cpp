class MinStack {
public:
   stack<pair<int,int>>st;
   // stores : { current val , min val encountered till that value}
  
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
       st.push({value,value});
        }
        else{
            if(value>st.top().second){
                st.push({value,st.top().second});
            }
            else{
                st.push({value,value});
            }
        }
    }
    
    void pop() {
        return st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
       return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */