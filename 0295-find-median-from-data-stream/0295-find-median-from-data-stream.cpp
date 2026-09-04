class MedianFinder {
public:
   // left -> max heap
   // right -> min heap

   priority_queue<int>left_max;
   priority_queue<int , vector<int>  , greater<int>>right_min;


    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // add to left max heap
        if(left_max.size()==0 || num <=left_max.top())left_max.push(num);
        else right_min.push(num);

      // left size greater than right size by 2 or more
       if(left_max.size() > right_min.size() + 1){
          right_min.push(left_max.top());
          left_max.pop();
       }
      
       // if right size is greater than left by 1
        if(left_max.size() +1  == right_min.size()){
            left_max.push(right_min.top());
            right_min.pop();
        }
    
    

    }
    
    double findMedian() {
        if(right_min.size()== left_max.size()){
            return (left_max.top()+right_min.top())/2.0;
        }
        return left_max.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */